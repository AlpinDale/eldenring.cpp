use anyhow::{anyhow, Context, Result};
use clap::Parser;
use std::collections::{BTreeMap, HashMap, HashSet};
use std::fs;
use std::path::{Path, PathBuf};
use syn::{
    Attribute, Fields, File, GenericArgument, Generics, Item, Lit, PathArguments, Type, Visibility,
};
use walkdir::WalkDir;

#[derive(Parser, Debug)]
#[command(author, version, about)]
struct Args {
    /// Path to fromsoftware-rs (repo root)
    #[arg(long, default_value = "../../third_party/fromsoftware-rs")]
    fsrs: PathBuf,
    /// Output include directory (eldenring/)
    #[arg(long, default_value = "../../include/eldenring")]
    out: PathBuf,
}

#[derive(Clone, Debug)]
struct SourceCrate {
    name: String,
    src_root: PathBuf,
    ns_root: Vec<String>,
    rust_crate: String,
}

#[derive(Clone, Debug)]
struct FieldDef {
    name: String,
    ty: Type,
}

#[derive(Clone, Debug)]
struct StructDef {
    name: String,
    module: Vec<String>,
    crate_root: String,
    generics: Vec<String>,
    repr_c: bool,
    repr_transparent: bool,
    fields: Vec<FieldDef>,
    is_unit: bool,
    opaque: bool,
    use_map: HashMap<String, Vec<String>>,
}

#[derive(Clone, Debug)]
struct EnumDef {
    name: String,
    module: Vec<String>,
    crate_root: String,
    repr: Option<String>,
    variants: Vec<(String, Option<i64>)>,
}

#[derive(Clone, Debug)]
struct TypeAliasDef {
    name: String,
    module: Vec<String>,
    crate_root: String,
    target: Type,
    generics: Vec<String>,
    use_map: HashMap<String, Vec<String>>,
}

#[derive(Clone, Debug)]
struct UseAliasDef {
    name: String,
    module: Vec<String>,
    crate_root: String,
    path: Vec<String>,
}

#[derive(Clone, Debug)]
struct UseGlobDef {
    module: Vec<String>,
    crate_root: String,
    target: Vec<String>,
}

#[derive(Clone, Debug)]
enum ItemDef {
    Struct(StructDef),
    Enum(EnumDef),
    TypeAlias(TypeAliasDef),
    UseAlias(UseAliasDef),
}

fn is_public(vis: &Visibility) -> bool {
    matches!(vis, Visibility::Public(_))
}

fn parse_repr(attrs: &[Attribute]) -> (bool, bool, Option<String>) {
    let mut repr_c = false;
    let mut repr_transparent = false;
    let mut repr_int: Option<String> = None;
    for attr in attrs {
        if !attr.path().is_ident("repr") {
            continue;
        }
        let _ = attr.parse_nested_meta(|meta| {
            if meta.path.is_ident("C") {
                repr_c = true;
            } else if meta.path.is_ident("transparent") {
                repr_transparent = true;
            } else if let Some(ident) = meta.path.get_ident() {
                let name = ident.to_string();
                match name.as_str() {
                    "u8" | "u16" | "u32" | "u64" | "usize" | "i8" | "i16" | "i32" | "i64"
                    | "isize" => {
                        repr_int = Some(name);
                    }
                    _ => {}
                }
            }
            Ok(())
        });
    }
    (repr_c, repr_transparent, repr_int)
}

fn module_from_path(path: &Path) -> Vec<String> {
    let mut parts: Vec<String> = path
        .components()
        .map(|c| c.as_os_str().to_string_lossy().to_string())
        .collect();
    if let Some(last) = parts.last() {
        if last == "mod.rs" {
            parts.pop();
        } else if last == "lib.rs" || last == "main.rs" {
            parts.pop();
        } else if last.ends_with(".rs") {
            let trimmed = last.trim_end_matches(".rs");
            *parts.last_mut().unwrap() = trimmed.to_string();
        }
    }
    parts
}

fn collect_uses(
    file: &File,
    module: &[String],
    crate_info: &SourceCrate,
) -> HashMap<String, Vec<String>> {
    let mut raw = HashMap::new();
    for item in &file.items {
        if let Item::Use(u) = item {
            collect_use_tree(&u.tree, Vec::new(), &mut raw);
        }
    }
    let mut map = HashMap::new();
    for (key, path) in raw {
        map.insert(key, resolve_use_path(&path, module, crate_info));
    }
    map
}

fn collect_use_tree(
    tree: &syn::UseTree,
    prefix: Vec<String>,
    map: &mut HashMap<String, Vec<String>>,
) {
    match tree {
        syn::UseTree::Name(n) => {
            let mut path = prefix;
            path.push(n.ident.to_string());
            map.insert(n.ident.to_string(), path);
        }
        syn::UseTree::Rename(r) => {
            let mut path = prefix;
            path.push(r.ident.to_string());
            map.insert(r.rename.to_string(), path);
        }
        syn::UseTree::Path(p) => {
            let mut path = prefix;
            path.push(p.ident.to_string());
            collect_use_tree(&p.tree, path, map);
        }
        syn::UseTree::Group(g) => {
            for t in &g.items {
                collect_use_tree(t, prefix.clone(), map);
            }
        }
        syn::UseTree::Glob(_) => {}
    }
}

fn is_type_like_name(name: &str) -> bool {
    name.chars()
        .next()
        .map(|c| c.is_uppercase())
        .unwrap_or(false)
}

fn is_cpp_keyword(name: &str) -> bool {
    matches!(
        name,
        "alignas"
            | "alignof"
            | "and"
            | "and_eq"
            | "asm"
            | "atomic_cancel"
            | "atomic_commit"
            | "atomic_noexcept"
            | "auto"
            | "bitand"
            | "bitor"
            | "bool"
            | "break"
            | "case"
            | "catch"
            | "char"
            | "char8_t"
            | "char16_t"
            | "char32_t"
            | "class"
            | "compl"
            | "concept"
            | "const"
            | "consteval"
            | "constexpr"
            | "constinit"
            | "const_cast"
            | "continue"
            | "co_await"
            | "co_return"
            | "co_yield"
            | "decltype"
            | "default"
            | "delete"
            | "do"
            | "double"
            | "dynamic_cast"
            | "else"
            | "enum"
            | "explicit"
            | "export"
            | "extern"
            | "false"
            | "float"
            | "for"
            | "friend"
            | "goto"
            | "if"
            | "inline"
            | "int"
            | "long"
            | "mutable"
            | "namespace"
            | "new"
            | "noexcept"
            | "not"
            | "not_eq"
            | "nullptr"
            | "operator"
            | "or"
            | "or_eq"
            | "private"
            | "protected"
            | "public"
            | "register"
            | "reinterpret_cast"
            | "requires"
            | "return"
            | "short"
            | "signed"
            | "sizeof"
            | "static"
            | "static_assert"
            | "static_cast"
            | "struct"
            | "switch"
            | "synchronized"
            | "template"
            | "this"
            | "thread_local"
            | "throw"
            | "true"
            | "try"
            | "typedef"
            | "typeid"
            | "typename"
            | "union"
            | "unsigned"
            | "using"
            | "virtual"
            | "void"
            | "volatile"
            | "wchar_t"
            | "while"
            | "xor"
            | "xor_eq"
    )
}

fn sanitize_ident(name: &str) -> String {
    if is_cpp_keyword(name) {
        format!("kw_{}", name)
    } else {
        name.to_string()
    }
}

fn sanitize_cpp_path(path: &str) -> String {
    if path.is_empty() {
        return String::new();
    }
    let parts: Vec<String> = path.split("::").map(sanitize_ident).collect();
    parts.join("::")
}

fn collect_use_aliases(
    tree: &syn::UseTree,
    prefix: Vec<String>,
    out: &mut Vec<(String, Vec<String>)>,
) {
    match tree {
        syn::UseTree::Name(n) => {
            let mut path = prefix;
            path.push(n.ident.to_string());
            out.push((n.ident.to_string(), path));
        }
        syn::UseTree::Rename(r) => {
            let mut path = prefix;
            path.push(r.ident.to_string());
            out.push((r.rename.to_string(), path));
        }
        syn::UseTree::Path(p) => {
            let mut path = prefix;
            path.push(p.ident.to_string());
            collect_use_aliases(&p.tree, path, out);
        }
        syn::UseTree::Group(g) => {
            for t in &g.items {
                collect_use_aliases(t, prefix.clone(), out);
            }
        }
        syn::UseTree::Glob(_) => {}
    }
}

fn collect_pub_use_globs(file: &File) -> Vec<Vec<String>> {
    let mut out = Vec::new();
    for item in &file.items {
        if let Item::Use(u) = item {
            if !is_public(&u.vis) {
                continue;
            }
            collect_glob_from_use(&u.tree, Vec::new(), &mut out);
        }
    }
    out
}

fn collect_glob_from_use(tree: &syn::UseTree, prefix: Vec<String>, out: &mut Vec<Vec<String>>) {
    match tree {
        syn::UseTree::Glob(_) => {
            out.push(prefix);
        }
        syn::UseTree::Path(p) => {
            let mut path = prefix;
            path.push(p.ident.to_string());
            collect_glob_from_use(&p.tree, path, out);
        }
        syn::UseTree::Group(g) => {
            for t in &g.items {
                collect_glob_from_use(t, prefix.clone(), out);
            }
        }
        syn::UseTree::Name(_) | syn::UseTree::Rename(_) => {}
    }
}

fn parse_bitfield_block(
    block: &str,
    module: &[String],
    crate_info: &SourceCrate,
    use_map: &HashMap<String, Vec<String>>,
) -> Vec<ItemDef> {
    let mut out = Vec::new();
    let mut search = block;
    while let Some(pos) = search.find("pub struct") {
        let rest = &search[pos + "pub struct".len()..];
        let (name, after_name) = parse_ident(rest);
        if name.is_empty() {
            search = &rest[1..];
            continue;
        }
        let mut chars = after_name.chars();
        let mut ty = None;
        while let Some(c) = chars.next() {
            if c == '(' {
                if let Some(end) = chars.as_str().find(')') {
                    let ty_str = chars.as_str()[..end].trim();
                    ty = syn::parse_str::<Type>(ty_str).ok();
                }
                break;
            }
        }
        if let Some(ty) = ty {
            out.push(ItemDef::Struct(StructDef {
                name: name.to_string(),
                module: module.to_vec(),
                crate_root: crate_info.ns_root.join("::"),
                generics: Vec::new(),
                repr_c: true,
                repr_transparent: false,
                fields: vec![FieldDef {
                    name: "value".to_string(),
                    ty,
                }],
                is_unit: false,
                opaque: false,
                use_map: use_map.clone(),
            }));
        }
        search = &rest;
    }
    out
}

fn parse_bitflags_block(
    block: &str,
    module: &[String],
    crate_info: &SourceCrate,
    use_map: &HashMap<String, Vec<String>>,
) -> Vec<ItemDef> {
    let mut out = Vec::new();
    let mut search = block;
    while let Some(pos) = search.find("pub struct") {
        let rest = &search[pos + "pub struct".len()..];
        let (name, after_name) = parse_ident(rest);
        if name.is_empty() {
            search = &rest[1..];
            continue;
        }
        let mut chars = after_name.chars();
        let mut ty = None;
        while let Some(c) = chars.next() {
            if c == ':' {
                let tail = chars.as_str();
                let mut end = tail.len();
                for (idx, ch) in tail.char_indices() {
                    if ch == '{' || ch == ';' || ch.is_whitespace() {
                        end = idx;
                        break;
                    }
                }
                let ty_str = tail[..end].trim();
                ty = syn::parse_str::<Type>(ty_str).ok();
                break;
            }
        }
        if let Some(ty) = ty {
            out.push(ItemDef::Struct(StructDef {
                name: name.to_string(),
                module: module.to_vec(),
                crate_root: crate_info.ns_root.join("::"),
                generics: Vec::new(),
                repr_c: true,
                repr_transparent: false,
                fields: vec![FieldDef {
                    name: "value".to_string(),
                    ty,
                }],
                is_unit: false,
                opaque: false,
                use_map: use_map.clone(),
            }));
        }
        search = &rest;
    }
    out
}

fn parse_ident(input: &str) -> (String, &str) {
    let mut name = String::new();
    let mut rest = input;
    let mut chars = input.chars();
    while let Some(c) = chars.next() {
        if c.is_alphanumeric() || c == '_' {
            name.push(c);
        } else if !name.is_empty() {
            rest = chars.as_str();
            break;
        }
    }
    (name, rest)
}

fn generics_params(g: &Generics) -> Vec<String> {
    g.params
        .iter()
        .filter_map(|p| match p {
            syn::GenericParam::Type(tp) => Some(tp.ident.to_string()),
            syn::GenericParam::Lifetime(_) => None,
            syn::GenericParam::Const(cp) => Some(cp.ident.to_string()),
        })
        .collect()
}

fn is_zero_sized(ty: &Type) -> bool {
    if let Type::Path(p) = ty {
        if p.path.segments.len() == 1 {
            let ident = p.path.segments[0].ident.to_string();
            return ident == "PhantomData";
        }
    }
    false
}

fn resolve_use_path(raw: &[String], module: &[String], crate_info: &SourceCrate) -> Vec<String> {
    if raw.is_empty() {
        return Vec::new();
    }
    let mut idx = 0usize;
    let mut base: Vec<String> = module.to_vec();
    if raw[idx] == "crate" {
        idx += 1;
        base.clear();
    } else if raw[idx] == "self" {
        idx += 1;
    } else {
        while idx < raw.len() && raw[idx] == "super" {
            if !base.is_empty() {
                base.pop();
            }
            idx += 1;
        }
        if idx < raw.len() && raw[idx] == "self" {
            idx += 1;
        } else if idx < raw.len() && raw[idx] == "crate" {
            idx += 1;
            base.clear();
        }
    }
    if idx == 0 {
        let first = &raw[0];
        if first == &crate_info.name || first == &crate_info.rust_crate {
            idx = 1;
            base.clear();
        } else if first == "shared" || first == "fromsoftware_shared" {
            return raw.to_vec();
        }
    }
    let mut out = base;
    out.extend_from_slice(&raw[idx..]);
    out
}

fn cpp_primitive(ident: &str) -> Option<&'static str> {
    match ident {
        "u8" => Some("std::uint8_t"),
        "u16" => Some("std::uint16_t"),
        "u32" => Some("std::uint32_t"),
        "u64" => Some("std::uint64_t"),
        "usize" => Some("std::uintptr_t"),
        "i8" => Some("std::int8_t"),
        "i16" => Some("std::int16_t"),
        "i32" => Some("std::int32_t"),
        "i64" => Some("std::int64_t"),
        "isize" => Some("std::intptr_t"),
        "f32" => Some("float"),
        "f64" => Some("double"),
        "bool" => Some("bool"),
        _ => None,
    }
}

fn is_unmappable_prelude(ident: &str) -> bool {
    matches!(
        ident,
        "Result"
            | "Vec"
            | "String"
            | "Cow"
            | "Box"
            | "Rc"
            | "Arc"
            | "Cell"
            | "RefCell"
            | "Mutex"
            | "RwLock"
            | "HashMap"
            | "HashSet"
            | "BTreeMap"
            | "BTreeSet"
            | "VecDeque"
            | "BinaryHeap"
    )
}

fn path_to_cpp(path: &syn::Path, crate_root: &str, current_ns: &str) -> String {
    let mut segs: Vec<String> = path.segments.iter().map(|s| s.ident.to_string()).collect();
    if segs.is_empty() {
        return crate_root.to_string();
    }
    if segs[0] == "crate" || segs[0] == "self" || segs[0] == "super" {
        segs.remove(0);
        let mut out = sanitize_cpp_path(crate_root);
        if !segs.is_empty() {
            out.push_str("::");
            let sanitized: Vec<String> = segs.iter().map(|s| sanitize_ident(s)).collect();
            out.push_str(&sanitized.join("::"));
        }
        return out;
    }
    if segs[0] == "shared" || segs[0] == "fromsoftware_shared" {
        segs.remove(0);
        let mut out = "eldenring::shared".to_string();
        if !segs.is_empty() {
            out.push_str("::");
            let sanitized: Vec<String> = segs.iter().map(|s| sanitize_ident(s)).collect();
            out.push_str(&sanitized.join("::"));
        }
        return out;
    }
    if segs.len() == 1 {
        let mut out = sanitize_cpp_path(current_ns);
        if !out.is_empty() {
            out.push_str("::");
        }
        let sanitized: Vec<String> = segs.iter().map(|s| sanitize_ident(s)).collect();
        out.push_str(&sanitized.join("::"));
        return out;
    }
    let mut out = sanitize_cpp_path(crate_root);
    out.push_str("::");
    let sanitized: Vec<String> = segs.iter().map(|s| sanitize_ident(s)).collect();
    out.push_str(&sanitized.join("::"));
    out
}

fn segments_to_cpp(segs: &[String], crate_root: &str) -> String {
    if segs.is_empty() {
        return sanitize_cpp_path(crate_root);
    }
    if segs[0] == "shared" || segs[0] == "fromsoftware_shared" {
        let mut out = "eldenring::shared".to_string();
        if segs.len() > 1 {
            out.push_str("::");
            let sanitized: Vec<String> = segs[1..].iter().map(|s| sanitize_ident(s)).collect();
            out.push_str(&sanitized.join("::"));
        }
        return out;
    }
    if segs[0] == "crate" || segs[0] == "self" || segs[0] == "super" {
        let mut out = sanitize_cpp_path(crate_root);
        if segs.len() > 1 {
            out.push_str("::");
            let sanitized: Vec<String> = segs[1..].iter().map(|s| sanitize_ident(s)).collect();
            out.push_str(&sanitized.join("::"));
        }
        return out;
    }
    let mut out = sanitize_cpp_path(crate_root);
    out.push_str("::");
    let sanitized: Vec<String> = segs.iter().map(|s| sanitize_ident(s)).collect();
    out.push_str(&sanitized.join("::"));
    out
}

fn cpp_full_name(crate_root: &str, module: &[String], name: &str) -> String {
    let mut out = sanitize_cpp_path(crate_root);
    if !module.is_empty() {
        out.push_str("::");
        let segs: Vec<String> = module.iter().map(|s| sanitize_ident(s)).collect();
        out.push_str(&segs.join("::"));
    }
    if !out.is_empty() {
        out.push_str("::");
    }
    out.push_str(&sanitize_ident(name));
    out
}

fn collect_value_deps(
    ty: &Type,
    crate_root: &str,
    current_ns: &str,
    generics: &[String],
    use_map: &HashMap<String, Vec<String>>,
) -> Vec<String> {
    match ty {
        Type::Ptr(_) => Vec::new(),
        Type::Array(arr) => {
            collect_value_deps(&arr.elem, crate_root, current_ns, generics, use_map)
        }
        Type::Path(p) => {
            let seg = match p.path.segments.last() {
                Some(s) => s,
                None => return Vec::new(),
            };
            let ident = seg.ident.to_string();
            if cpp_primitive(&ident).is_some() {
                return Vec::new();
            }
            if generics.contains(&ident) {
                return Vec::new();
            }
            if ident == "Option" || ident == "NonNull" {
                return Vec::new();
            }
            if ident == "OwnedPtr" {
                return vec!["eldenring::shared::owned_pointer::OwnedPtr".to_string()];
            }
            if ident == "IncompleteArrayField" {
                return vec![
                    "eldenring::shared::util::incomplete_array_field::IncompleteArrayField"
                        .to_string(),
                ];
            }
            if ident == "UnknownStruct" {
                return vec!["eldenring::shared::util::unknown_struct::UnknownStruct".to_string()];
            }
            if ident == "ManuallyDrop" || ident == "MaybeUninit" {
                if let PathArguments::AngleBracketed(args) = &seg.arguments {
                    if let Some(GenericArgument::Type(inner)) = args.args.first() {
                        return collect_value_deps(
                            inner, crate_root, current_ns, generics, use_map,
                        );
                    }
                }
                return Vec::new();
            }
            if is_unmappable_prelude(&ident) && !use_map.contains_key(&ident) {
                return Vec::new();
            }
            let cpp = if let Some(mapped) = use_map.get(&ident) {
                segments_to_cpp(mapped, crate_root)
            } else {
                path_to_cpp(&p.path, crate_root, current_ns)
            };
            Vec::from([cpp])
        }
        _ => Vec::new(),
    }
}

fn type_to_cpp(
    ty: &Type,
    crate_root: &str,
    current_ns: &str,
    generics: &[String],
    use_map: &HashMap<String, Vec<String>>,
) -> Option<String> {
    let current_ns = sanitize_cpp_path(current_ns);
    if is_zero_sized(ty) {
        return None;
    }
    match ty {
        Type::Path(p) => {
            if p.qself.is_some() {
                return None;
            }
            let seg = p.path.segments.last()?;
            let ident = seg.ident.to_string();
            if let Some(prim) = cpp_primitive(&ident) {
                return Some(prim.to_string());
            }
            if generics.contains(&ident) {
                return Some(ident);
            }
            if let Some(first) = p.path.segments.first() {
                let first_ident = first.ident.to_string();
                if generics.contains(&first_ident) && p.path.segments.len() > 1 {
                    let sanitized: Vec<String> = p
                        .path
                        .segments
                        .iter()
                        .map(|s| sanitize_ident(&s.ident.to_string()))
                        .collect();
                    return Some(format!("typename {}", sanitized.join("::")));
                }
            }
            if ident == "c_void" {
                return Some("void".to_string());
            }
            if is_unmappable_prelude(&ident) && !use_map.contains_key(&ident) {
                return None;
            }
            if ident == "Option" {
                if let PathArguments::AngleBracketed(args) = &seg.arguments {
                    if let Some(GenericArgument::Type(inner)) = args.args.first() {
                        if let Some(ptr) = pointer_like_cpp(
                            inner,
                            crate_root,
                            current_ns.as_str(),
                            generics,
                            use_map,
                        ) {
                            return Some(ptr);
                        }
                    }
                }
                return None;
            }
            if ident == "NonNull" {
                if let PathArguments::AngleBracketed(args) = &seg.arguments {
                    if let Some(GenericArgument::Type(inner)) = args.args.first() {
                        if let Some(base) =
                            type_to_cpp(inner, crate_root, current_ns.as_str(), generics, use_map)
                        {
                            return Some(format!("{}*", base));
                        }
                    }
                }
                return None;
            }
            if ident == "OwnedPtr" {
                if let PathArguments::AngleBracketed(args) = &seg.arguments {
                    if let Some(GenericArgument::Type(inner)) = args.args.first() {
                        if let Some(base) =
                            type_to_cpp(inner, crate_root, current_ns.as_str(), generics, use_map)
                        {
                            return Some(format!(
                                "eldenring::shared::owned_pointer::OwnedPtr<{}>",
                                base
                            ));
                        }
                    }
                }
                return None;
            }
            if ident == "ManuallyDrop" || ident == "MaybeUninit" {
                if let PathArguments::AngleBracketed(args) = &seg.arguments {
                    if let Some(GenericArgument::Type(inner)) = args.args.first() {
                        return type_to_cpp(
                            inner,
                            crate_root,
                            current_ns.as_str(),
                            generics,
                            use_map,
                        );
                    }
                }
                return None;
            }
            if let Some(mapped) = use_map.get(&ident) {
                if let Some(first) = mapped.first() {
                    if first == "std" || first == "core" || first == "alloc" {
                        return None;
                    }
                }
                let mut base = segments_to_cpp(mapped, crate_root);
                if let PathArguments::AngleBracketed(args) = &seg.arguments {
                    let mut mapped_args = Vec::new();
                    for arg in args.args.iter() {
                        if let GenericArgument::Type(t) = arg {
                            let c =
                                type_to_cpp(t, crate_root, current_ns.as_str(), generics, use_map)?;
                            mapped_args.push(c);
                        }
                    }
                    if !mapped_args.is_empty() {
                        base.push('<');
                        base.push_str(&mapped_args.join(", "));
                        base.push('>');
                    }
                }
                return Some(base);
            }

            // Generic path
            let mut cpp_path = path_to_cpp(&p.path, crate_root, current_ns.as_str());
            if let PathArguments::AngleBracketed(args) = &seg.arguments {
                let mut mapped = Vec::new();
                for arg in args.args.iter() {
                    if let GenericArgument::Type(t) = arg {
                        let c = type_to_cpp(t, crate_root, current_ns.as_str(), generics, use_map)?;
                        mapped.push(c);
                    }
                }
                if !mapped.is_empty() {
                    cpp_path.push('<');
                    cpp_path.push_str(&mapped.join(", "));
                    cpp_path.push('>');
                }
            }
            Some(cpp_path)
        }
        Type::Ptr(p) => {
            let inner = type_to_cpp(&p.elem, crate_root, current_ns.as_str(), generics, use_map)?;
            let qual = if p.mutability.is_some() { "" } else { "const " };
            Some(format!("{}{}*", qual, inner))
        }
        Type::Array(arr) => {
            let elem = type_to_cpp(
                &arr.elem,
                crate_root,
                current_ns.as_str(),
                generics,
                use_map,
            )?;
            let len = match &arr.len {
                syn::Expr::Lit(lit) => {
                    if let Lit::Int(i) = &lit.lit {
                        i.base10_parse::<usize>().ok()?
                    } else {
                        return None;
                    }
                }
                _ => return None,
            };
            Some(format!("std::array<{}, {}>", elem, len))
        }
        _ => None,
    }
}

fn pointer_like_cpp(
    ty: &Type,
    crate_root: &str,
    current_ns: &str,
    generics: &[String],
    use_map: &HashMap<String, Vec<String>>,
) -> Option<String> {
    match ty {
        Type::Ptr(_) => type_to_cpp(ty, crate_root, current_ns, generics, use_map),
        Type::Path(p) => {
            let seg = p.path.segments.last()?;
            let ident = seg.ident.to_string();
            if ident == "NonNull" {
                if let PathArguments::AngleBracketed(args) = &seg.arguments {
                    if let Some(GenericArgument::Type(inner)) = args.args.first() {
                        if let Some(base) =
                            type_to_cpp(inner, crate_root, current_ns, generics, use_map)
                        {
                            return Some(format!("{}*", base));
                        }
                    }
                }
            }
            if ident == "OwnedPtr" {
                if let PathArguments::AngleBracketed(args) = &seg.arguments {
                    if let Some(GenericArgument::Type(inner)) = args.args.first() {
                        if let Some(base) =
                            type_to_cpp(inner, crate_root, current_ns, generics, use_map)
                        {
                            return Some(format!(
                                "eldenring::shared::owned_pointer::OwnedPtr<{}>",
                                base
                            ));
                        }
                    }
                }
            }
            None
        }
        _ => None,
    }
}

fn collect_items(crate_info: &SourceCrate) -> Result<Vec<ItemDef>> {
    let mut items = Vec::new();
    let mut globs = Vec::new();
    for entry in WalkDir::new(&crate_info.src_root)
        .into_iter()
        .filter_map(|e| e.ok())
    {
        let path = entry.path();
        if !path.is_file() {
            continue;
        }
        if path.extension().and_then(|s| s.to_str()) != Some("rs") {
            continue;
        }
        let rel = path.strip_prefix(&crate_info.src_root).unwrap();
        let module = module_from_path(rel);
        let content =
            fs::read_to_string(path).with_context(|| format!("read {:?}", path.display()))?;
        let file =
            syn::parse_file(&content).with_context(|| format!("parse {:?}", path.display()))?;
        let (found, found_globs) = collect_from_file(&file, &content, &module, crate_info);
        items.extend(found);
        globs.extend(found_globs);
    }
    add_glob_reexports(&mut items, globs);
    Ok(items)
}

fn collect_from_file(
    file: &File,
    _content: &str,
    module: &[String],
    crate_info: &SourceCrate,
) -> (Vec<ItemDef>, Vec<UseGlobDef>) {
    let mut out = Vec::new();
    let mut globs = Vec::new();
    let use_map = collect_uses(file, module, crate_info);
    for item in &file.items {
        match item {
            Item::Macro(m) => {
                let ident = m.mac.path.segments.last().map(|s| s.ident.to_string());
                let block = m.mac.tokens.to_string();
                if matches!(ident.as_deref(), Some("bitfield")) {
                    out.extend(parse_bitfield_block(&block, module, crate_info, &use_map));
                } else if matches!(ident.as_deref(), Some("bitflags")) {
                    out.extend(parse_bitflags_block(&block, module, crate_info, &use_map));
                }
            }
            Item::Struct(s) => {
                if !is_public(&s.vis) {
                    continue;
                }
                let (repr_c, repr_transparent, _repr_int) = parse_repr(&s.attrs);
                let generics = generics_params(&s.generics);
                let mut fields = Vec::new();
                let mut is_unit = false;
                match &s.fields {
                    Fields::Named(named) => {
                        for f in &named.named {
                            let name = f.ident.as_ref().unwrap().to_string();
                            fields.push(FieldDef {
                                name,
                                ty: f.ty.clone(),
                            });
                        }
                    }
                    Fields::Unnamed(unnamed) => {
                        for (idx, f) in unnamed.unnamed.iter().enumerate() {
                            fields.push(FieldDef {
                                name: format!("_{}", idx),
                                ty: f.ty.clone(),
                            });
                        }
                    }
                    Fields::Unit => {
                        is_unit = true;
                    }
                }

                out.push(ItemDef::Struct(StructDef {
                    name: s.ident.to_string(),
                    module: module.to_vec(),
                    crate_root: crate_info.ns_root.join("::"),
                    generics,
                    repr_c,
                    repr_transparent,
                    fields,
                    is_unit,
                    opaque: false,
                    use_map: use_map.clone(),
                }));
            }
            Item::Enum(e) => {
                if !is_public(&e.vis) {
                    continue;
                }
                let (_repr_c, _repr_transparent, repr_int) = parse_repr(&e.attrs);
                let mut variants = Vec::new();
                let mut next_val: i64 = 0;
                for v in &e.variants {
                    let mut val = None;
                    if let Some((_, expr)) = &v.discriminant {
                        if let syn::Expr::Lit(lit) = expr {
                            if let Lit::Int(int) = &lit.lit {
                                if let Ok(parsed) = int.base10_parse::<i64>() {
                                    val = Some(parsed);
                                    next_val = parsed + 1;
                                }
                            }
                        }
                    }
                    if val.is_none() {
                        val = Some(next_val);
                        next_val += 1;
                    }
                    variants.push((v.ident.to_string(), val));
                }
                out.push(ItemDef::Enum(EnumDef {
                    name: e.ident.to_string(),
                    module: module.to_vec(),
                    crate_root: crate_info.ns_root.join("::"),
                    repr: repr_int,
                    variants,
                }));
            }
            Item::Type(t) => {
                if !is_public(&t.vis) {
                    continue;
                }
                let generics = generics_params(&t.generics);
                out.push(ItemDef::TypeAlias(TypeAliasDef {
                    name: t.ident.to_string(),
                    module: module.to_vec(),
                    crate_root: crate_info.ns_root.join("::"),
                    target: t.ty.as_ref().clone(),
                    generics,
                    use_map: use_map.clone(),
                }));
            }
            Item::Use(u) => {
                if !is_public(&u.vis) {
                    continue;
                }
                let mut aliases = Vec::new();
                collect_use_aliases(&u.tree, Vec::new(), &mut aliases);
                for (alias, path) in aliases {
                    if !is_type_like_name(&alias) {
                        continue;
                    }
                    let resolved = resolve_use_path(&path, module, crate_info);
                    if let Some(first) = resolved.first() {
                        if matches!(first.as_str(), "std" | "core" | "alloc" | "from_singleton") {
                            continue;
                        }
                    }
                    out.push(ItemDef::UseAlias(UseAliasDef {
                        name: alias,
                        module: module.to_vec(),
                        crate_root: crate_info.ns_root.join("::"),
                        path: resolved,
                    }));
                }
            }
            _ => {}
        }
    }
    for glob in collect_pub_use_globs(file) {
        let resolved = resolve_use_path(&glob, module, crate_info);
        if resolved.is_empty() {
            continue;
        }
        globs.push(UseGlobDef {
            module: module.to_vec(),
            crate_root: crate_info.ns_root.join("::"),
            target: resolved,
        });
    }
    (out, globs)
}

fn determine_opaque(items: &mut [ItemDef]) {
    let mut opaque_map: HashMap<String, bool> = HashMap::new();
    let mut generic_structs: HashSet<String> = HashSet::new();
    let mut known_types: HashSet<String> = HashSet::new();
    let mut alias_map: HashMap<String, String> = HashMap::new();

    for item in items.iter() {
        if let ItemDef::Struct(s) = item {
            if !s.generics.is_empty() {
                let full_name = cpp_full_name(&s.crate_root, &s.module, &s.name);
                generic_structs.insert(full_name);
            }
            let full_name = cpp_full_name(&s.crate_root, &s.module, &s.name);
            known_types.insert(full_name);
        }
        if let ItemDef::Enum(e) = item {
            let full_name = cpp_full_name(&e.crate_root, &e.module, &e.name);
            known_types.insert(full_name);
        }
        if let ItemDef::TypeAlias(t) = item {
            let full_name = cpp_full_name(&t.crate_root, &t.module, &t.name);
            known_types.insert(full_name.clone());
            if !t.generics.is_empty() {
                generic_structs.insert(full_name);
            }
        }
        if let ItemDef::UseAlias(u) = item {
            let full_name = cpp_full_name(&u.crate_root, &u.module, &u.name);
            known_types.insert(full_name);
        }
    }

    for item in items.iter() {
        match item {
            ItemDef::TypeAlias(t) => {
                let alias_full = cpp_full_name(&t.crate_root, &t.module, &t.name);
                let current_ns_raw = if t.module.is_empty() {
                    t.crate_root.clone()
                } else {
                    format!("{}::{}", t.crate_root, t.module.join("::"))
                };
                let current_ns = sanitize_cpp_path(&current_ns_raw);
                if let Some(target) = type_to_cpp(
                    &t.target,
                    &t.crate_root,
                    &current_ns,
                    &t.generics,
                    &t.use_map,
                ) {
                    alias_map.insert(alias_full, target);
                }
            }
            ItemDef::UseAlias(u) => {
                let alias_full = cpp_full_name(&u.crate_root, &u.module, &u.name);
                let target = segments_to_cpp(&u.path, &u.crate_root);
                alias_map.insert(alias_full, target);
            }
            _ => {}
        }
    }

    for (alias, target) in alias_map.iter() {
        let mut resolved = target.clone();
        for _ in 0..4 {
            if let Some(next) = alias_map.get(&resolved) {
                resolved = next.clone();
            } else {
                break;
            }
        }
        if let Some(true) = opaque_map.get(&resolved) {
            opaque_map.insert(alias.clone(), true);
        }
        if generic_structs.contains(&resolved) {
            generic_structs.insert(alias.clone());
        }
    }

    for item in items.iter_mut() {
        if let ItemDef::Struct(s) = item {
            if !(s.repr_c || s.repr_transparent) || s.is_unit {
                s.opaque = true;
            } else {
                let mut ok = true;
                for field in &s.fields {
                    if is_zero_sized(&field.ty) {
                        continue;
                    }
                    let current_ns_raw = if s.module.is_empty() {
                        s.crate_root.clone()
                    } else {
                        format!("{}::{}", s.crate_root, s.module.join("::"))
                    };
                    let current_ns = sanitize_cpp_path(&current_ns_raw);
                    let deps = collect_value_deps(
                        &field.ty,
                        &s.crate_root,
                        &current_ns,
                        &s.generics,
                        &s.use_map,
                    );
                    if deps.iter().any(|d| {
                        let mut resolved = d.clone();
                        for _ in 0..4 {
                            if let Some(next) = alias_map.get(&resolved) {
                                resolved = next.clone();
                            } else {
                                break;
                            }
                        }
                        !known_types.contains(&resolved)
                    }) {
                        ok = false;
                        break;
                    }
                    if let Type::Path(p) = &field.ty {
                        let seg = p.path.segments.last().map(|s| &s.arguments);
                        let has_args = matches!(seg, Some(PathArguments::AngleBracketed(_)));
                        if !has_args {
                            let ident = p.path.segments.last().unwrap().ident.to_string();
                            let dep = if let Some(mapped) = s.use_map.get(&ident) {
                                segments_to_cpp(mapped, &s.crate_root)
                            } else {
                                path_to_cpp(&p.path, &s.crate_root, &current_ns)
                            };
                            if generic_structs.contains(&dep) {
                                ok = false;
                                break;
                            }
                        }
                    }
                    if type_to_cpp(
                        &field.ty,
                        &s.crate_root,
                        &current_ns,
                        &s.generics,
                        &s.use_map,
                    )
                    .is_none()
                    {
                        ok = false;
                        break;
                    }
                }
                if !ok {
                    s.opaque = true;
                }
            }
            let full_name = cpp_full_name(&s.crate_root, &s.module, &s.name);
            opaque_map.insert(full_name, s.opaque);
        }
    }

    for item in items.iter() {
        if let ItemDef::Enum(e) = item {
            let full_name = cpp_full_name(&e.crate_root, &e.module, &e.name);
            let is_opaque = e.repr.is_none();
            opaque_map.insert(full_name, is_opaque);
        }
    }

    let mut changed = true;
    while changed {
        changed = false;
        for item in items.iter_mut() {
            let s = match item {
                ItemDef::Struct(s) => s,
                _ => continue,
            };
            if s.opaque {
                continue;
            }
            let current_ns_raw = if s.module.is_empty() {
                s.crate_root.clone()
            } else {
                format!("{}::{}", s.crate_root, s.module.join("::"))
            };
            let current_ns = sanitize_cpp_path(&current_ns_raw);
            let mut depends_on_opaque = false;
            for field in &s.fields {
                if is_zero_sized(&field.ty) {
                    continue;
                }
                let deps = collect_value_deps(
                    &field.ty,
                    &s.crate_root,
                    &current_ns,
                    &s.generics,
                    &s.use_map,
                );
                for dep in deps {
                    let mut resolved = dep.clone();
                    for _ in 0..4 {
                        if let Some(next) = alias_map.get(&resolved) {
                            resolved = next.clone();
                        } else {
                            break;
                        }
                    }
                    if let Some(true) = opaque_map.get(&resolved) {
                        depends_on_opaque = true;
                        break;
                    }
                }
                if depends_on_opaque {
                    break;
                }
            }
            if depends_on_opaque {
                s.opaque = true;
                let full_name = cpp_full_name(&s.crate_root, &s.module, &s.name);
                opaque_map.insert(full_name, true);
                changed = true;
            }
        }
    }
}

fn write_forward_decls(out_root: &Path, items: &[ItemDef]) -> Result<()> {
    enum DeclKind {
        Struct(Vec<String>),
        Enum(Option<String>),
    }
    enum AliasKind {
        TypeAlias(String, Vec<String>),
        UseAlias(String, Vec<String>),
    }
    let mut decls: BTreeMap<Vec<String>, Vec<(String, DeclKind)>> = BTreeMap::new();
    let mut aliases: BTreeMap<Vec<String>, Vec<(String, AliasKind)>> = BTreeMap::new();
    let mut template_structs: HashMap<String, Vec<String>> = HashMap::new();
    for item in items {
        if let ItemDef::Struct(s) = item {
            if !s.generics.is_empty() {
                let full = cpp_full_name(&s.crate_root, &s.module, &s.name);
                template_structs.insert(full, s.generics.clone());
            }
        }
    }
    for item in items {
        match item {
            ItemDef::Struct(s) => {
                let mut ns: Vec<String> = s
                    .crate_root
                    .split("::")
                    .map(|s| sanitize_ident(s))
                    .collect();
                ns.extend(s.module.iter().map(|s| sanitize_ident(s)));
                decls
                    .entry(ns)
                    .or_default()
                    .push((s.name.clone(), DeclKind::Struct(s.generics.clone())));
            }
            ItemDef::Enum(e) => {
                let mut ns: Vec<String> = e
                    .crate_root
                    .split("::")
                    .map(|s| sanitize_ident(s))
                    .collect();
                ns.extend(e.module.iter().map(|s| sanitize_ident(s)));
                decls
                    .entry(ns)
                    .or_default()
                    .push((e.name.clone(), DeclKind::Enum(e.repr.clone())));
            }
            ItemDef::TypeAlias(t) => {
                let mut ns: Vec<String> = t
                    .crate_root
                    .split("::")
                    .map(|s| sanitize_ident(s))
                    .collect();
                ns.extend(t.module.iter().map(|s| sanitize_ident(s)));
                let current_ns_raw = if t.module.is_empty() {
                    t.crate_root.clone()
                } else {
                    format!("{}::{}", t.crate_root, t.module.join("::"))
                };
                let current_ns = sanitize_cpp_path(&current_ns_raw);
                if let Some(target) = type_to_cpp(
                    &t.target,
                    &t.crate_root,
                    &current_ns,
                    &t.generics,
                    &t.use_map,
                ) {
                    aliases.entry(ns).or_default().push((
                        t.name.clone(),
                        AliasKind::TypeAlias(target, t.generics.clone()),
                    ));
                }
            }
            ItemDef::UseAlias(u) => {
                let mut ns: Vec<String> = u
                    .crate_root
                    .split("::")
                    .map(|s| sanitize_ident(s))
                    .collect();
                ns.extend(u.module.iter().map(|s| sanitize_ident(s)));
                let target = segments_to_cpp(&u.path, &u.crate_root);
                let params = template_structs.get(&target).cloned().unwrap_or_default();
                aliases
                    .entry(ns)
                    .or_default()
                    .push((u.name.clone(), AliasKind::UseAlias(target, params)));
            }
        }
    }

    let mut content = String::new();
    content.push_str("#pragma once\n\n");
    content.push_str("// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.\n\n");
    content.push_str("#include <cstdint>\n\n");

    for (ns, mut defs) in decls {
        defs.sort_by(|a, b| a.0.cmp(&b.0));
        for seg in &ns {
            content.push_str(&format!("namespace {} {{\n", seg));
        }
        for (name, kind) in defs {
            let name = sanitize_ident(&name);
            match kind {
                DeclKind::Struct(generics) => {
                    if !generics.is_empty() {
                        content.push_str("template <");
                        let params: Vec<String> =
                            generics.iter().map(|g| format!("typename {}", g)).collect();
                        content.push_str(&params.join(", "));
                        content.push_str(">\n");
                    }
                    content.push_str(&format!("struct {};\n", name));
                }
                DeclKind::Enum(repr) => {
                    if let Some(r) = repr {
                        let cpp_repr = cpp_primitive(&r).unwrap_or("std::int32_t");
                        content.push_str(&format!("enum class {} : {};\n", name, cpp_repr));
                    } else {
                        content.push_str(&format!("enum class {};\n", name));
                    }
                }
            }
        }
        for _ in &ns {
            content.push_str("}\n");
        }
        content.push('\n');
    }

    let mut alias_entries: Vec<(Vec<String>, Vec<(String, AliasKind)>)> =
        aliases.into_iter().collect();
    alias_entries.sort_by(|a, b| {
        let len_a = a.0.len();
        let len_b = b.0.len();
        len_b.cmp(&len_a).then_with(|| a.0.cmp(&b.0))
    });
    for (ns, mut defs) in alias_entries {
        defs.sort_by(|a, b| a.0.cmp(&b.0));
        for seg in &ns {
            content.push_str(&format!("namespace {} {{\n", seg));
        }
        for (name, kind) in defs {
            let name = sanitize_ident(&name);
            match kind {
                AliasKind::TypeAlias(target, generics) => {
                    if !generics.is_empty() {
                        content.push_str("template <");
                        let params: Vec<String> =
                            generics.iter().map(|g| format!("typename {}", g)).collect();
                        content.push_str(&params.join(", "));
                        content.push_str(">\n");
                    }
                    content.push_str(&format!("using {} = {};\n", name, target));
                }
                AliasKind::UseAlias(target, params) => {
                    if !params.is_empty() {
                        content.push_str("template <");
                        let args: Vec<String> =
                            params.iter().map(|g| format!("typename {}", g)).collect();
                        content.push_str(&args.join(", "));
                        content.push_str(">\n");
                        let target_with_args = format!("{}<{}>", target, params.join(", "));
                        content.push_str(&format!("using {} = {};\n", name, target_with_args));
                    } else {
                        content.push_str(&format!("using {} = {};\n", name, target));
                    }
                }
            }
        }
        for _ in &ns {
            content.push_str("}\n");
        }
        content.push('\n');
    }

    fs::write(out_root.join("fwd.hpp"), content)?;
    Ok(())
}

fn write_headers(out_root: &Path, items: &[ItemDef]) -> Result<()> {
    let mut modules: BTreeMap<(String, Vec<String>), Vec<&ItemDef>> = BTreeMap::new();
    for item in items {
        let opt = match item {
            ItemDef::Struct(s) => Some((s.module.clone(), s.crate_root.clone())),
            ItemDef::Enum(e) => Some((e.module.clone(), e.crate_root.clone())),
            ItemDef::TypeAlias(_) => None,
            ItemDef::UseAlias(_) => None,
        };
        if let Some((module, crate_root)) = opt {
            modules.entry((crate_root, module)).or_default().push(item);
        }
    }

    let mut module_headers: HashMap<(String, Vec<String>), PathBuf> = HashMap::new();
    let mut module_deps: HashMap<(String, Vec<String>), HashSet<(String, Vec<String>)>> =
        HashMap::new();
    let mut type_to_module: HashMap<String, (String, Vec<String>)> = HashMap::new();
    let mut alias_map: HashMap<String, String> = HashMap::new();

    for item in items {
        match item {
            ItemDef::Struct(s) => {
                if s.opaque {
                    continue;
                }
                let name = cpp_full_name(&s.crate_root, &s.module, &s.name);
                type_to_module.insert(name, (s.crate_root.clone(), s.module.clone()));
            }
            ItemDef::Enum(e) => {
                if e.repr.is_none() {
                    continue;
                }
                let name = cpp_full_name(&e.crate_root, &e.module, &e.name);
                type_to_module.insert(name, (e.crate_root.clone(), e.module.clone()));
            }
            _ => {}
        }
    }

    for item in items {
        match item {
            ItemDef::TypeAlias(t) => {
                let alias_full = cpp_full_name(&t.crate_root, &t.module, &t.name);
                let current_ns_raw = if t.module.is_empty() {
                    t.crate_root.clone()
                } else {
                    format!("{}::{}", t.crate_root, t.module.join("::"))
                };
                let current_ns = sanitize_cpp_path(&current_ns_raw);
                if let Some(target) = type_to_cpp(
                    &t.target,
                    &t.crate_root,
                    &current_ns,
                    &t.generics,
                    &t.use_map,
                ) {
                    alias_map.insert(alias_full, target);
                }
            }
            ItemDef::UseAlias(u) => {
                let alias_full = cpp_full_name(&u.crate_root, &u.module, &u.name);
                let target = segments_to_cpp(&u.path, &u.crate_root);
                alias_map.insert(alias_full, target);
            }
            _ => {}
        }
    }

    for ((crate_root, module), defs) in modules {
        let prefix = if crate_root == "eldenring::shared" {
            "shared"
        } else {
            ""
        };
        let header_path = if module.is_empty() {
            if prefix.is_empty() {
                out_root.join("core.hpp")
            } else {
                out_root.join(prefix).join("core.hpp")
            }
        } else {
            let mut p = out_root.to_path_buf();
            if !prefix.is_empty() {
                p.push(prefix);
            }
            for seg in &module {
                p.push(seg);
            }
            p.set_extension("hpp");
            p
        };
        if let Some(parent) = header_path.parent() {
            fs::create_dir_all(parent)?;
        }
        let mut content = String::new();
        content.push_str("#pragma once\n\n");
        content.push_str("// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.\n\n");
        content.push_str("#include <cstdint>\n#include <cstddef>\n#include <array>\n");
        content.push_str("#include \"eldenring/support.hpp\"\n");
        content.push_str("#include \"eldenring/fwd.hpp\"\n\n");

        // namespaces
        let mut ns: Vec<String> = crate_root.split("::").map(|s| sanitize_ident(s)).collect();
        ns.extend(module.iter().map(|s| sanitize_ident(s)));
        for seg in &ns {
            content.push_str(&format!("namespace {} {{\n", seg));
        }
        content.push('\n');

        // Reorder definitions to satisfy by-value dependencies within the module.
        let mut def_items: Vec<&ItemDef> = Vec::new();
        let mut fwd_items: Vec<&ItemDef> = Vec::new();
        for item in &defs {
            match item {
                ItemDef::Struct(s) => {
                    if s.opaque {
                        fwd_items.push(item);
                    } else {
                        def_items.push(item);
                    }
                }
                ItemDef::Enum(e) => {
                    if e.repr.is_none() {
                        fwd_items.push(item);
                    } else {
                        def_items.push(item);
                    }
                }
                _ => {}
            }
        }

        let mut name_to_idx: HashMap<String, usize> = HashMap::new();
        for (idx, item) in def_items.iter().enumerate() {
            let full_name = match item {
                ItemDef::Struct(s) => cpp_full_name(&s.crate_root, &s.module, &s.name),
                ItemDef::Enum(e) => cpp_full_name(&e.crate_root, &e.module, &e.name),
                _ => continue,
            };
            name_to_idx.insert(full_name, idx);
        }

        let mut indegree = vec![0usize; def_items.len()];
        let mut edges: Vec<Vec<usize>> = vec![Vec::new(); def_items.len()];
        for (idx, item) in def_items.iter().enumerate() {
            let s = match item {
                ItemDef::Struct(s) => s,
                _ => continue,
            };
            let current_ns_raw = if s.module.is_empty() {
                s.crate_root.clone()
            } else {
                format!("{}::{}", s.crate_root, s.module.join("::"))
            };
            let current_ns = sanitize_cpp_path(&current_ns_raw);
            for field in &s.fields {
                if is_zero_sized(&field.ty) {
                    continue;
                }
                let deps = collect_value_deps(
                    &field.ty,
                    &s.crate_root,
                    &current_ns,
                    &s.generics,
                    &s.use_map,
                );
                for dep in deps {
                    if let Some(dep_mod) = type_to_module.get(&dep) {
                        if *dep_mod != (s.crate_root.clone(), s.module.clone()) {
                            continue;
                        }
                        if let Some(&dep_idx) = name_to_idx.get(&dep) {
                            edges[dep_idx].push(idx);
                            indegree[idx] += 1;
                        }
                    }
                }
            }
        }

        let mut queue: Vec<usize> = indegree
            .iter()
            .enumerate()
            .filter_map(|(i, &d)| if d == 0 { Some(i) } else { None })
            .collect();
        let mut ordered_defs = Vec::new();
        while let Some(i) = queue.pop() {
            ordered_defs.push(def_items[i]);
            for &n in &edges[i] {
                indegree[n] -= 1;
                if indegree[n] == 0 {
                    queue.push(n);
                }
            }
        }
        if ordered_defs.len() != def_items.len() {
            ordered_defs = def_items.clone();
        }

        for item in ordered_defs.into_iter().chain(fwd_items.into_iter()) {
            match item {
                ItemDef::Struct(s) => {
                    if s.opaque {
                        if !s.generics.is_empty() {
                            content.push_str("template <");
                            let params: Vec<String> = s
                                .generics
                                .iter()
                                .map(|g| format!("typename {}", g))
                                .collect();
                            content.push_str(&params.join(", "));
                            content.push_str(">\n");
                        }
                        content.push_str(&format!("struct {};\n\n", sanitize_ident(&s.name)));
                        continue;
                    }
                    if !s.generics.is_empty() {
                        content.push_str("template <");
                        let params: Vec<String> = s
                            .generics
                            .iter()
                            .map(|g| format!("typename {}", g))
                            .collect();
                        content.push_str(&params.join(", "));
                        content.push_str(">\n");
                    }
                    content.push_str(&format!("struct {} {{\n", sanitize_ident(&s.name)));
                    let current_ns_raw = if s.module.is_empty() {
                        s.crate_root.clone()
                    } else {
                        format!("{}::{}", s.crate_root, s.module.join("::"))
                    };
                    let current_ns = sanitize_cpp_path(&current_ns_raw);
                    for field in &s.fields {
                        if is_zero_sized(&field.ty) {
                            continue;
                        }
                        let ty = type_to_cpp(
                            &field.ty,
                            &s.crate_root,
                            &current_ns,
                            &s.generics,
                            &s.use_map,
                        )
                        .ok_or_else(|| anyhow!("unmappable field {}::{}", s.name, field.name))?;
                        content.push_str(&format!("  {} {};\n", ty, sanitize_ident(&field.name)));
                    }
                    content.push_str("};\n\n");
                }
                ItemDef::Enum(e) => {
                    if let Some(repr) = &e.repr {
                        let cpp_repr = cpp_primitive(repr).unwrap_or("std::int32_t");
                        content.push_str(&format!(
                            "enum class {} : {} {{\n",
                            sanitize_ident(&e.name),
                            cpp_repr
                        ));
                        for (name, val) in &e.variants {
                            let name = sanitize_ident(name);
                            if let Some(v) = val {
                                content.push_str(&format!("  {} = {},\n", name, v));
                            } else {
                                content.push_str(&format!("  {},\n", name));
                            }
                        }
                        content.push_str("};\n\n");
                    } else {
                        content.push_str(&format!("enum class {};\n\n", sanitize_ident(&e.name)));
                    }
                }
                ItemDef::TypeAlias(_) => {}
                ItemDef::UseAlias(_) => {}
            }
        }

        for _ in &ns {
            content.push_str("}\n");
        }

        fs::write(&header_path, content)?;
        module_headers.insert((crate_root, module), header_path);
    }

    // build module dependency graph for umbrella ordering
    for item in items {
        let s = match item {
            ItemDef::Struct(s) => s,
            _ => continue,
        };
        if s.opaque {
            continue;
        }
        let current_ns_raw = if s.module.is_empty() {
            s.crate_root.clone()
        } else {
            format!("{}::{}", s.crate_root, s.module.join("::"))
        };
        let current_ns = sanitize_cpp_path(&current_ns_raw);
        let key = (s.crate_root.clone(), s.module.clone());
        let deps = module_deps.entry(key.clone()).or_default();
        for field in &s.fields {
            if is_zero_sized(&field.ty) {
                continue;
            }
            let type_deps = collect_value_deps(
                &field.ty,
                &s.crate_root,
                &current_ns,
                &s.generics,
                &s.use_map,
            );
            for dep in type_deps {
                let mut resolved = dep.clone();
                for _ in 0..4 {
                    if let Some(next) = alias_map.get(&resolved) {
                        resolved = next.clone();
                    } else {
                        break;
                    }
                }
                if let Some(dep_mod) = type_to_module.get(&resolved) {
                    if *dep_mod != key {
                        deps.insert(dep_mod.clone());
                    }
                }
            }
        }
    }

    // write umbrella header
    let mut umbrella = String::new();
    umbrella.push_str("#pragma once\n\n");
    umbrella.push_str("// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.\n\n");
    umbrella.push_str("#include \"eldenring/support.hpp\"\n\n");

    let mut ordered_modules: Vec<(String, Vec<String>)> = module_headers.keys().cloned().collect();
    ordered_modules.sort();
    let mut dep_map: HashMap<(String, Vec<String>), HashSet<(String, Vec<String>)>> =
        module_deps.clone();
    for key in &ordered_modules {
        dep_map.entry(key.clone()).or_default();
    }

    let mut sorted = Vec::new();
    let mut no_deps: Vec<(String, Vec<String>)> = dep_map
        .iter()
        .filter_map(|(k, v)| if v.is_empty() { Some(k.clone()) } else { None })
        .collect();
    no_deps.sort();
    while let Some(node) = no_deps.pop() {
        sorted.push(node.clone());
        for (k, v) in dep_map.iter_mut() {
            if v.remove(&node) && v.is_empty() {
                no_deps.push(k.clone());
            }
        }
    }
    if sorted.len() != dep_map.len() {
        // Fallback to lexical ordering on cycles.
        sorted = ordered_modules;
    }

    for key in sorted {
        if let Some(path) = module_headers.get(&key) {
            let rel = path.strip_prefix(out_root).unwrap();
            umbrella.push_str(&format!(
                "#include \"eldenring/{}\"\n",
                rel.to_string_lossy()
            ));
        }
    }
    fs::write(out_root.join("eldenring.hpp"), &umbrella)?;
    fs::write(out_root.join("core.hpp"), &umbrella)?;

    Ok(())
}

#[derive(Clone, Debug)]
struct ExportTarget {
    crate_root: String,
    path: Vec<String>,
}

fn alias_target_from_path(path: &[String], current_crate_root: &str) -> ExportTarget {
    if let Some(first) = path.first() {
        if first == "shared" || first == "fromsoftware_shared" {
            return ExportTarget {
                crate_root: "eldenring::shared".to_string(),
                path: path[1..].to_vec(),
            };
        }
    }
    ExportTarget {
        crate_root: current_crate_root.to_string(),
        path: path.to_vec(),
    }
}

fn add_glob_reexports(items: &mut Vec<ItemDef>, globs: Vec<UseGlobDef>) {
    type ModuleKey = (String, Vec<String>);
    let mut direct_exports: HashMap<ModuleKey, HashMap<String, ExportTarget>> = HashMap::new();
    for item in items.iter() {
        match item {
            ItemDef::Struct(s) => {
                let key = (s.crate_root.clone(), s.module.clone());
                let mut path = s.module.clone();
                path.push(s.name.clone());
                direct_exports.entry(key).or_default().insert(
                    s.name.clone(),
                    ExportTarget {
                        crate_root: s.crate_root.clone(),
                        path,
                    },
                );
            }
            ItemDef::Enum(e) => {
                let key = (e.crate_root.clone(), e.module.clone());
                let mut path = e.module.clone();
                path.push(e.name.clone());
                direct_exports.entry(key).or_default().insert(
                    e.name.clone(),
                    ExportTarget {
                        crate_root: e.crate_root.clone(),
                        path,
                    },
                );
            }
            ItemDef::TypeAlias(t) => {
                let key = (t.crate_root.clone(), t.module.clone());
                let mut path = t.module.clone();
                path.push(t.name.clone());
                direct_exports.entry(key).or_default().insert(
                    t.name.clone(),
                    ExportTarget {
                        crate_root: t.crate_root.clone(),
                        path,
                    },
                );
            }
            ItemDef::UseAlias(u) => {
                let key = (u.crate_root.clone(), u.module.clone());
                let target = alias_target_from_path(&u.path, &u.crate_root);
                direct_exports
                    .entry(key)
                    .or_default()
                    .insert(u.name.clone(), target);
            }
        }
    }

    let mut globs_by_module: HashMap<ModuleKey, Vec<ModuleKey>> = HashMap::new();
    for glob in globs {
        let key = (glob.crate_root.clone(), glob.module.clone());
        let (target_root, target_path) = if let Some(first) = glob.target.first() {
            if first == "shared" || first == "fromsoftware_shared" {
                ("eldenring::shared".to_string(), glob.target[1..].to_vec())
            } else {
                (glob.crate_root.clone(), glob.target.clone())
            }
        } else {
            (glob.crate_root.clone(), glob.target.clone())
        };
        globs_by_module
            .entry(key)
            .or_default()
            .push((target_root, target_path));
    }

    fn collect_exports(
        key: &ModuleKey,
        direct: &HashMap<ModuleKey, HashMap<String, ExportTarget>>,
        globs: &HashMap<ModuleKey, Vec<ModuleKey>>,
        memo: &mut HashMap<ModuleKey, HashMap<String, ExportTarget>>,
        visiting: &mut HashSet<ModuleKey>,
    ) -> HashMap<String, ExportTarget> {
        if let Some(cached) = memo.get(key) {
            return cached.clone();
        }
        if !visiting.insert(key.clone()) {
            return direct.get(key).cloned().unwrap_or_default();
        }
        let mut exports = direct.get(key).cloned().unwrap_or_default();
        if let Some(targets) = globs.get(key) {
            for target in targets {
                let target_exports = collect_exports(target, direct, globs, memo, visiting);
                for (name, target_path) in target_exports {
                    exports.entry(name).or_insert(target_path);
                }
            }
        }
        visiting.remove(key);
        memo.insert(key.clone(), exports.clone());
        exports
    }

    let mut memo: HashMap<ModuleKey, HashMap<String, ExportTarget>> = HashMap::new();
    let mut visiting: HashSet<ModuleKey> = HashSet::new();
    let mut new_aliases = Vec::new();

    for (module_key, targets) in globs_by_module.iter() {
        let mut existing: HashSet<String> = direct_exports
            .get(module_key)
            .map(|m| m.keys().cloned().collect())
            .unwrap_or_default();
        for target in targets {
            let exports = collect_exports(
                target,
                &direct_exports,
                &globs_by_module,
                &mut memo,
                &mut visiting,
            );
            for (name, export_target) in exports {
                if existing.contains(&name) {
                    continue;
                }
                let path = if export_target.crate_root == module_key.0 {
                    export_target.path.clone()
                } else if export_target.crate_root == "eldenring::shared" {
                    let mut p = vec!["shared".to_string()];
                    p.extend(export_target.path.clone());
                    p
                } else {
                    continue;
                };
                new_aliases.push(ItemDef::UseAlias(UseAliasDef {
                    name: name.clone(),
                    module: module_key.1.clone(),
                    crate_root: module_key.0.clone(),
                    path,
                }));
                existing.insert(name);
            }
        }
    }

    items.extend(new_aliases);
}

fn main() -> Result<()> {
    let args = Args::parse();
    let fsrs = args.fsrs.canonicalize()?;
    let out = args.out;
    fs::create_dir_all(&out)?;
    let out = out.canonicalize()?;

    let crates = vec![
        SourceCrate {
            name: "eldenring".to_string(),
            src_root: fsrs.join("crates/eldenring/src"),
            ns_root: vec!["eldenring".to_string()],
            rust_crate: "eldenring".to_string(),
        },
        SourceCrate {
            name: "shared".to_string(),
            src_root: fsrs.join("crates/shared/src"),
            ns_root: vec!["eldenring".to_string(), "shared".to_string()],
            rust_crate: "fromsoftware_shared".to_string(),
        },
    ];

    let mut all_items = Vec::new();
    for c in crates.iter() {
        let mut items = collect_items(c)?;
        // determine opaque for this crate
        determine_opaque(&mut items);
        all_items.extend(items);
    }
    write_forward_decls(&out, &all_items)?;
    write_headers(&out, &all_items)?;

    Ok(())
}
