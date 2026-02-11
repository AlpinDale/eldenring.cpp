use std::collections::{BTreeMap, HashMap};
use std::fs;
use std::path::{Path, PathBuf};

use anyhow::{Context, Result};
use clap::Parser;
use quote::ToTokens;
use syn::{
    File, FnArg, GenericArgument, Generics, ImplItem, Item, Lit, PathArguments, ReturnType, Type,
    Visibility,
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
    /// Report output path
    #[arg(long, default_value = "../../api_parity_report.md")]
    report: PathBuf,
}

#[derive(Clone, Debug)]
struct SourceCrate {
    name: String,
    src_root: PathBuf,
    ns_root: Vec<String>,
    rust_crate: String,
}

#[derive(Clone, Debug)]
struct FnDef {
    name: String,
    module: Vec<String>,
    file: String,
    kind: String,
    impl_name: Option<String>,
    impl_self_ty: Option<Type>,
    pattern: FnPattern,
    rva: Option<String>,
    sig: syn::Signature,
    use_map: HashMap<String, Vec<String>>,
}

#[derive(Clone, Debug)]
enum FnPattern {
    Stub,
    RvaValue,
    RvaToVa,
    RvaCall,
    LoadStaticDirect,
    LoadStaticIndirect,
}

#[derive(Clone, Debug)]
struct ReportEntry {
    name: String,
    kind: String,
    impl_name: Option<String>,
    pattern: String,
    rva: Option<String>,
}

fn is_public(vis: &Visibility) -> bool {
    matches!(vis, Visibility::Public(_))
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
        if is_external_crate_root(first) {
            return raw.to_vec();
        }
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
            | "Option"
            | "Vec"
            | "String"
            | "str"
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

fn is_external_crate_root(ident: &str) -> bool {
    matches!(
        ident,
        "std"
            | "core"
            | "alloc"
            | "windows"
            | "pelite"
            | "bitfield"
            | "bitflags"
            | "vtable_rs"
            | "thiserror"
            | "serde"
            | "serde_json"
            | "regex"
            | "lazy_static"
            | "once_cell"
            | "log"
            | "tracing"
            | "parking_lot"
            | "rayon"
            | "anyhow"
            | "bytemuck"
            | "num"
            | "glam"
            | "uuid"
            | "winapi"
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

fn is_unit_type(ty: &Type) -> bool {
    matches!(ty, Type::Tuple(t) if t.elems.is_empty())
}

fn type_to_cpp(
    ty: &Type,
    crate_root: &str,
    current_ns: &str,
    generics: &[String],
    use_map: &HashMap<String, Vec<String>>,
    self_ty: Option<&str>,
) -> Option<String> {
    let current_ns = sanitize_cpp_path(current_ns);
    match ty {
        Type::Path(p) => {
            if p.qself.is_some() {
                return None;
            }
            if let Some(first) = p.path.segments.first() {
                let root = first.ident.to_string();
                if is_external_crate_root(&root) {
                    return None;
                }
            }
            let seg = p.path.segments.last()?;
            let ident = seg.ident.to_string();
            if ident == "Self" {
                return self_ty.map(|s| s.to_string());
            }
            if let Some(prim) = cpp_primitive(&ident) {
                return Some(prim.to_string());
            }
            if generics.contains(&ident) {
                return Some(ident);
            }
            if ident == "c_void" {
                return Some("void".to_string());
            }
            if is_unmappable_prelude(&ident) && !use_map.contains_key(&ident) {
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
                            let c = type_to_cpp(
                                t,
                                crate_root,
                                current_ns.as_str(),
                                generics,
                                use_map,
                                self_ty,
                            )?;
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
            let mut cpp_path = path_to_cpp(&p.path, crate_root, current_ns.as_str());
            if let PathArguments::AngleBracketed(args) = &seg.arguments {
                let mut mapped = Vec::new();
                for arg in args.args.iter() {
                    if let GenericArgument::Type(t) = arg {
                        let c = type_to_cpp(
                            t,
                            crate_root,
                            current_ns.as_str(),
                            generics,
                            use_map,
                            self_ty,
                        )?;
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
            let inner = type_to_cpp(
                &p.elem,
                crate_root,
                current_ns.as_str(),
                generics,
                use_map,
                self_ty,
            )?;
            let qual = if p.mutability.is_some() { "" } else { "const " };
            Some(format!("{}{}*", qual, inner))
        }
        Type::Reference(r) => {
            let inner = type_to_cpp(
                &r.elem,
                crate_root,
                current_ns.as_str(),
                generics,
                use_map,
                self_ty,
            )?;
            let qual = if r.mutability.is_some() { "" } else { "const " };
            Some(format!("{}{}*", qual, inner))
        }
        Type::Array(arr) => {
            let elem = type_to_cpp(
                &arr.elem,
                crate_root,
                current_ns.as_str(),
                generics,
                use_map,
                self_ty,
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

fn extract_rva_field(block: &syn::Block) -> Option<String> {
    let s = block.to_token_stream().to_string();
    let re = regex::Regex::new(r"rva\s*::\s*get\s*\(\s*\)\s*\.\s*([A-Za-z0-9_]+)").ok()?;
    re.captures(&s)
        .and_then(|c| c.get(1).map(|m| m.as_str().to_string()))
}

fn detect_pattern(block: &syn::Block) -> (FnPattern, Option<String>) {
    let s = block.to_token_stream().to_string();
    let rva = extract_rva_field(block);

    if s.contains("load_static_direct") {
        return (FnPattern::LoadStaticDirect, rva);
    }
    if s.contains("load_static_indirect") {
        return (FnPattern::LoadStaticIndirect, rva);
    }
    if s.contains("rva_to_va") {
        if rva.is_some() {
            if s.contains("transmute") {
                let call_re = regex::Regex::new(r"\bcall\s*\(").ok();
                if call_re.as_ref().is_some_and(|re| re.is_match(&s)) {
                    return (FnPattern::RvaCall, rva);
                }
            }
            return (FnPattern::RvaToVa, rva);
        }
    }
    if rva.is_some() {
        return (FnPattern::RvaValue, rva);
    }
    (FnPattern::Stub, None)
}

fn pattern_label(pattern: &FnPattern) -> &'static str {
    match pattern {
        FnPattern::Stub => "stub",
        FnPattern::RvaValue => "rva_value",
        FnPattern::RvaToVa => "rva_to_va",
        FnPattern::RvaCall => "rva_call",
        FnPattern::LoadStaticDirect => "load_static_direct",
        FnPattern::LoadStaticIndirect => "load_static_indirect",
    }
}

fn default_return_expr() -> &'static str {
    "{}"
}

fn emit_unused_params(param_names: &[String]) -> String {
    if param_names.is_empty() {
        "(void)0; ".to_string()
    } else {
        format!("(void){}; ", param_names.join(", "))
    }
}

fn emit_stub_body(ret: &str, param_names: &[String]) -> String {
    let unused = emit_unused_params(param_names);
    if ret == "void" {
        unused
    } else {
        format!("{}return {}; ", unused, default_return_expr())
    }
}

fn is_pointer_ret(ret: &str) -> bool {
    ret.contains('*')
}

fn is_integral_ret(ret: &str) -> bool {
    ret == "bool"
        || ret.starts_with("std::uint")
        || ret.starts_with("std::int")
        || ret == "std::uintptr_t"
        || ret == "std::intptr_t"
}

fn emit_body(
    pattern: &FnPattern,
    rva: &Option<String>,
    ret: &str,
    param_names: &[String],
) -> String {
    let args = if param_names.is_empty() {
        String::new()
    } else {
        param_names.join(", ")
    };
    let args_with_comma = if args.is_empty() {
        String::new()
    } else {
        format!(", {}", args)
    };
    let rva_name = match rva {
        Some(name) => name.as_str(),
        None => return emit_stub_body(ret, param_names),
    };

    match pattern {
        FnPattern::RvaCall => {
            if ret == "void" {
                format!(
                    "eldenring::api::runtime::call_rva<void>(eldenring::api::rva::get().{}{});",
                    rva_name, args_with_comma
                )
            } else {
                format!(
                    "return eldenring::api::runtime::call_rva<{}>(eldenring::api::rva::get().{}{});",
                    ret, rva_name, args_with_comma
                )
            }
        }
        FnPattern::RvaToVa => {
            if ret == "void" || (!is_pointer_ret(ret) && !is_integral_ret(ret)) {
                emit_stub_body(ret, param_names)
            } else {
                format!(
                    "return eldenring::api::runtime::rva_to_va<{}>(eldenring::api::rva::get().{});",
                    ret, rva_name
                )
            }
        }
        FnPattern::RvaValue => {
            if ret == "void" {
                emit_stub_body(ret, param_names)
            } else if is_pointer_ret(ret) {
                format!(
                    "return eldenring::api::runtime::rva_to_va<{}>(eldenring::api::rva::get().{});",
                    ret, rva_name
                )
            } else if is_integral_ret(ret) {
                format!(
                    "return static_cast<{}>(eldenring::api::rva::get().{});",
                    ret, rva_name
                )
            } else {
                emit_stub_body(ret, param_names)
            }
        }
        FnPattern::LoadStaticDirect => {
            if ret == "void" || !is_pointer_ret(ret) {
                emit_stub_body(ret, param_names)
            } else {
                let unused = emit_unused_params(param_names);
                format!(
                    "{}return eldenring::api::runtime::load_static_direct<{}>(eldenring::api::rva::get().{});",
                    unused, ret, rva_name
                )
            }
        }
        FnPattern::LoadStaticIndirect => {
            if ret == "void" || !is_pointer_ret(ret) {
                emit_stub_body(ret, param_names)
            } else {
                let unused = emit_unused_params(param_names);
                format!(
                    "{}return eldenring::api::runtime::load_static_indirect<{}>(eldenring::api::rva::get().{});",
                    unused, ret, rva_name
                )
            }
        }
        FnPattern::Stub => emit_stub_body(ret, param_names),
    }
}

fn parse_rva_fields(path: &Path) -> Result<Vec<String>> {
    let content =
        fs::read_to_string(path).with_context(|| format!("read rva bundle {}", path.display()))?;
    let re = regex::Regex::new(r"^\s*pub\s+([A-Za-z0-9_]+)\s*:\s*u32").unwrap();
    let mut fields = Vec::new();
    for line in content.lines() {
        if let Some(cap) = re.captures(line) {
            fields.push(cap[1].to_string());
        }
    }
    if fields.is_empty() {
        return Err(anyhow::anyhow!(
            "no rva bundle fields found in {}",
            path.display()
        ));
    }
    Ok(fields)
}

fn parse_rva_values(path: &Path) -> Result<HashMap<String, u32>> {
    let content =
        fs::read_to_string(path).with_context(|| format!("read rva values {}", path.display()))?;
    let re = regex::Regex::new(r"^\s*([A-Za-z0-9_]+)\s*:\s*0x([0-9A-Fa-f]+)").unwrap();
    let mut values = HashMap::new();
    for line in content.lines() {
        if let Some(cap) = re.captures(line) {
            let name = cap[1].to_string();
            let value = u32::from_str_radix(&cap[2], 16)
                .with_context(|| format!("parse rva value {}", name))?;
            values.insert(name, value);
        }
    }
    if values.is_empty() {
        return Err(anyhow::anyhow!("no rva values found in {}", path.display()));
    }
    Ok(values)
}

fn write_api_runtime(out_dir: &Path, fsrs: &Path) -> Result<()> {
    let bundle_path = fsrs.join("crates/eldenring/src/rva/bundle.rs");
    let ww_path = fsrs.join("crates/eldenring/src/rva/rva_ww.rs");
    let jp_path = fsrs.join("crates/eldenring/src/rva/rva_jp.rs");

    let fields = parse_rva_fields(&bundle_path)?;
    let ww = parse_rva_values(&ww_path)?;
    let jp = parse_rva_values(&jp_path)?;

    let mut runtime = String::new();
    runtime.push_str("#pragma once\n\n");
    runtime.push_str("// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.\n\n");
    runtime.push_str("#include <cstdint>\n");
    runtime.push_str("#include <cstdio>\n");
    runtime.push_str("#include <string>\n");
    runtime.push_str("#include <type_traits>\n\n");
    runtime.push_str("#if defined(_WIN32)\n");
    runtime.push_str("#include <windows.h>\n");
    runtime.push_str("#endif\n\n");
    runtime.push_str("#ifdef _MSC_VER\n");
    runtime.push_str("#pragma comment(lib, \"version.lib\")\n");
    runtime.push_str("#endif\n\n");

    runtime.push_str("namespace eldenring { namespace api { namespace runtime {\n");
    runtime.push_str("inline std::uintptr_t module_base() {\n");
    runtime.push_str("#if defined(_WIN32)\n");
    runtime.push_str("  return reinterpret_cast<std::uintptr_t>(GetModuleHandleA(nullptr));\n");
    runtime.push_str("#else\n");
    runtime.push_str("  return 0;\n");
    runtime.push_str("#endif\n");
    runtime.push_str("}\n\n");

    runtime.push_str("inline std::uintptr_t rva_to_va_base(std::uint32_t rva) {\n");
    runtime.push_str("  return module_base() + static_cast<std::uintptr_t>(rva);\n");
    runtime.push_str("}\n\n");

    runtime.push_str("template <typename T>\n");
    runtime.push_str("inline T rva_to_va(std::uint32_t rva) {\n");
    runtime.push_str("  auto va = rva_to_va_base(rva);\n");
    runtime.push_str("  if constexpr (std::is_pointer_v<T>) {\n");
    runtime.push_str("    return reinterpret_cast<T>(va);\n");
    runtime.push_str("  } else {\n");
    runtime.push_str("    return static_cast<T>(va);\n");
    runtime.push_str("  }\n");
    runtime.push_str("}\n\n");

    runtime.push_str("template <typename Ret, typename... Args>\n");
    runtime.push_str("inline Ret call_rva(std::uint32_t rva, Args... args) {\n");
    runtime.push_str("  auto fn = reinterpret_cast<Ret(*)(Args...)>(rva_to_va_base(rva));\n");
    runtime.push_str("  if constexpr (std::is_void_v<Ret>) {\n");
    runtime.push_str("    fn(args...);\n");
    runtime.push_str("  } else {\n");
    runtime.push_str("    return fn(args...);\n");
    runtime.push_str("  }\n");
    runtime.push_str("}\n\n");

    runtime.push_str("template <typename T>\n");
    runtime.push_str("inline T load_static_direct(std::uint32_t rva) {\n");
    runtime.push_str("  return rva_to_va<T>(rva);\n");
    runtime.push_str("}\n\n");

    runtime.push_str("template <typename T>\n");
    runtime.push_str("inline T load_static_indirect(std::uint32_t rva) {\n");
    runtime.push_str("  auto addr = rva_to_va<std::uintptr_t*>(rva);\n");
    runtime.push_str("  if (!addr) {\n");
    runtime.push_str("    return T{};\n");
    runtime.push_str("  }\n");
    runtime.push_str("  return reinterpret_cast<T>(*addr);\n");
    runtime.push_str("}\n\n");

    runtime.push_str("inline bool get_file_version(std::string& out) {\n");
    runtime.push_str("#if defined(_WIN32)\n");
    runtime.push_str("  char path[MAX_PATH * 4] = {};\n");
    runtime.push_str(
        "  if (GetModuleFileNameA(nullptr, path, static_cast<DWORD>(sizeof(path))) == 0) {\n",
    );
    runtime.push_str("    return false;\n");
    runtime.push_str("  }\n\n");
    runtime.push_str("  DWORD handle = 0;\n");
    runtime.push_str("  DWORD size = GetFileVersionInfoSizeA(path, &handle);\n");
    runtime.push_str("  if (size == 0) {\n");
    runtime.push_str("    return false;\n");
    runtime.push_str("  }\n\n");
    runtime.push_str("  std::string data;\n");
    runtime.push_str("  data.resize(size);\n");
    runtime.push_str("  if (!GetFileVersionInfoA(path, handle, size, data.data())) {\n");
    runtime.push_str("    return false;\n");
    runtime.push_str("  }\n\n");
    runtime.push_str("  VS_FIXEDFILEINFO* info = nullptr;\n");
    runtime.push_str("  UINT info_len = 0;\n");
    runtime.push_str("  if (!VerQueryValueA(data.data(), \"\\\\\", reinterpret_cast<void**>(&info), &info_len)) {\n");
    runtime.push_str("    return false;\n");
    runtime.push_str("  }\n");
    runtime.push_str("  if (!info || info_len < sizeof(VS_FIXEDFILEINFO)) {\n");
    runtime.push_str("    return false;\n");
    runtime.push_str("  }\n\n");
    runtime.push_str("  const DWORD ms = info->dwProductVersionMS;\n");
    runtime.push_str("  const DWORD ls = info->dwProductVersionLS;\n");
    runtime.push_str("  const DWORD major = HIWORD(ms);\n");
    runtime.push_str("  const DWORD minor = LOWORD(ms);\n");
    runtime.push_str("  const DWORD patch = HIWORD(ls);\n");
    runtime.push_str("  const DWORD build = LOWORD(ls);\n\n");
    runtime.push_str("  char buffer[64] = {};\n");
    runtime.push_str("  std::snprintf(buffer, sizeof(buffer), \"%lu.%lu.%lu.%lu\",\n");
    runtime.push_str("                static_cast<unsigned long>(major),\n");
    runtime.push_str("                static_cast<unsigned long>(minor),\n");
    runtime.push_str("                static_cast<unsigned long>(patch),\n");
    runtime.push_str("                static_cast<unsigned long>(build));\n");
    runtime.push_str("  out.assign(buffer);\n");
    runtime.push_str("  return true;\n");
    runtime.push_str("#else\n");
    runtime.push_str("  (void)out;\n");
    runtime.push_str("  return false;\n");
    runtime.push_str("#endif\n");
    runtime.push_str("}\n");
    runtime.push_str("}}} // namespace eldenring::api::runtime\n\n");

    runtime.push_str("namespace eldenring { namespace api { namespace rva {\n");
    runtime.push_str("struct RvaBundle {\n");
    for field in &fields {
        runtime.push_str(&format!("  std::uint32_t {};\n", field));
    }
    runtime.push_str("};\n\n");
    runtime.push_str("inline const RvaBundle& get() {\n");
    runtime.push_str("  static const RvaBundle kRvaWw261{\n");
    for field in &fields {
        let value = ww.get(field).copied().unwrap_or(0);
        runtime.push_str(&format!("    0x{:x},\n", value));
    }
    runtime.push_str("  };\n");
    runtime.push_str("  static const RvaBundle kRvaJp2611{\n");
    for field in &fields {
        let value = jp.get(field).copied().unwrap_or(0);
        runtime.push_str(&format!("    0x{:x},\n", value));
    }
    runtime.push_str("  };\n");
    runtime.push_str("  static const RvaBundle* selected = nullptr;\n");
    runtime.push_str("  if (!selected) {\n");
    runtime.push_str("    std::string version;\n");
    runtime.push_str("    if (runtime::get_file_version(version)) {\n");
    runtime.push_str("      if (version == \"2.6.1.0\") {\n");
    runtime.push_str("        selected = &kRvaWw261;\n");
    runtime.push_str("      } else if (version == \"2.6.1.1\") {\n");
    runtime.push_str("        selected = &kRvaJp2611;\n");
    runtime.push_str("      }\n");
    runtime.push_str("    }\n");
    runtime.push_str("    if (!selected) {\n");
    runtime.push_str("      selected = &kRvaWw261;\n");
    runtime.push_str("    }\n");
    runtime.push_str("  }\n");
    runtime.push_str("  return *selected;\n");
    runtime.push_str("}\n");
    runtime.push_str("}}} // namespace eldenring::api::rva\n");

    fs::write(out_dir.join("api_runtime.hpp"), runtime)?;

    Ok(())
}

fn main() -> Result<()> {
    let args = Args::parse();
    let crate_info = SourceCrate {
        name: "eldenring".to_string(),
        src_root: args.fsrs.join("crates/eldenring/src"),
        ns_root: vec!["eldenring".to_string()],
        rust_crate: "eldenring".to_string(),
    };

    let mut fns: Vec<FnDef> = Vec::new();
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
        let file_rel = rel.to_string_lossy().replace('\\', "/");
        let content =
            fs::read_to_string(path).with_context(|| format!("read {:?}", path.display()))?;
        let file =
            syn::parse_file(&content).with_context(|| format!("parse {:?}", path.display()))?;
        let use_map = collect_uses(&file, &module, &crate_info);

        for item in file.items {
            match item {
                Item::Fn(f) => {
                    if !is_public(&f.vis) {
                        continue;
                    }
                    let block = *f.block;
                    let (pattern, rva) = detect_pattern(&block);
                    fns.push(FnDef {
                        name: f.sig.ident.to_string(),
                        module: module.clone(),
                        file: file_rel.clone(),
                        kind: "free".to_string(),
                        impl_name: None,
                        impl_self_ty: None,
                        pattern,
                        rva,
                        sig: f.sig,
                        use_map: use_map.clone(),
                    });
                }
                Item::Trait(t) => {
                    if !is_public(&t.vis) {
                        continue;
                    }
                    for item in t.items {
                        if let syn::TraitItem::Fn(tf) = item {
                            let block = tf.default.unwrap_or_else(|| syn::parse_quote!({}));
                            let (pattern, rva) = detect_pattern(&block);
                            fns.push(FnDef {
                                name: tf.sig.ident.to_string(),
                                module: module.clone(),
                                file: file_rel.clone(),
                                kind: "trait".to_string(),
                                impl_name: Some(t.ident.to_string()),
                                impl_self_ty: None,
                                pattern,
                                rva,
                                sig: tf.sig,
                                use_map: use_map.clone(),
                            });
                        }
                    }
                }
                Item::Impl(imp) => {
                    let self_ty = match imp.self_ty.as_ref() {
                        Type::Path(p) => p.path.segments.last().map(|s| s.ident.to_string()),
                        _ => None,
                    };
                    let Some(self_name) = self_ty else {
                        continue;
                    };
                    let is_trait_impl = imp.trait_.is_some();
                    for item in imp.items {
                        if let ImplItem::Fn(m) = item {
                            if !is_trait_impl && !is_public(&m.vis) {
                                continue;
                            }
                            let block = m.block;
                            let (pattern, rva) = detect_pattern(&block);
                            fns.push(FnDef {
                                name: m.sig.ident.to_string(),
                                module: module.clone(),
                                file: file_rel.clone(),
                                kind: "impl".to_string(),
                                impl_name: Some(self_name.clone()),
                                impl_self_ty: Some((*imp.self_ty).clone()),
                                pattern,
                                rva,
                                sig: m.sig,
                                use_map: use_map.clone(),
                            });
                        }
                    }
                }
                _ => {}
            }
        }
    }

    let mut by_module: BTreeMap<Vec<String>, Vec<FnDef>> = BTreeMap::new();
    for f in fns.into_iter() {
        by_module.entry(f.module.clone()).or_default().push(f);
    }

    let mut report_map: BTreeMap<String, BTreeMap<String, Vec<ReportEntry>>> = BTreeMap::new();
    let mut total = 0usize;
    let mut matched_count = 0usize;
    let mut stub_count = 0usize;
    for (module, funcs) in &by_module {
        let category = if module.is_empty() {
            "root".to_string()
        } else {
            module[0].clone()
        };
        for f in funcs {
            total += 1;
            let pattern = pattern_label(&f.pattern).to_string();
            let rva = f.rva.clone();
            if matches!(f.pattern, FnPattern::Stub) {
                stub_count += 1;
            } else {
                matched_count += 1;
            }
            let entry = ReportEntry {
                name: f.name.clone(),
                kind: f.kind.clone(),
                impl_name: f.impl_name.clone(),
                pattern,
                rva,
            };
            report_map
                .entry(category.clone())
                .or_default()
                .entry(f.file.clone())
                .or_default()
                .push(entry);
        }
    }

    let mut report = String::new();
    report.push_str("# eldenring.cpp API parity report\n\n");
    report.push_str("Auto-extracted from `fromsoftware-rs/crates/eldenring/src`.\n");
    report.push_str("Includes `pub fn` and methods in `pub trait` blocks.\n\n");
    report.push_str(&format!("Total functions: {}\n", total));
    report.push_str(&format!("Matched patterns: {}\n", matched_count));
    report.push_str(&format!("Unclassified (stub): {}\n\n", stub_count));

    report.push_str("## Categories\n");
    for (cat, files) in &report_map {
        let count: usize = files.values().map(|v| v.len()).sum();
        report.push_str(&format!("- {}: {}\n", cat, count));
    }
    report.push('\n');

    for (cat, files) in &report_map {
        report.push_str(&format!("# {}\n", cat));
        let mut file_keys: Vec<String> = files.keys().cloned().collect();
        file_keys.sort();
        for file in file_keys {
            report.push_str(&format!("## {}\n", file));
            let mut entries = files.get(&file).cloned().unwrap_or_default();
            entries.sort_by(|a, b| a.name.cmp(&b.name));
            for e in entries {
                let ctx = if let Some(imp) = e.impl_name.as_ref() {
                    format!("{} {}", e.kind, imp)
                } else {
                    e.kind.clone()
                };
                if let Some(rva) = e.rva.as_ref() {
                    report.push_str(&format!(
                        "- {} ({}, {}, rva={})\n",
                        e.name, ctx, e.pattern, rva
                    ));
                } else {
                    report.push_str(&format!("- {} ({}, {})\n", e.name, ctx, e.pattern));
                }
            }
            report.push('\n');
        }
        report.push('\n');
    }

    let mut api = String::new();
    api.push_str("#pragma once\n\n");
    api.push_str("// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.\n\n");
    api.push_str("#include \"eldenring/eldenring.hpp\"\n");
    api.push_str("#include \"eldenring/api_runtime.hpp\"\n\n");
    api.push_str("namespace eldenring { namespace api {\n");

    for (module, mut funcs) in by_module {
        funcs.sort_by(|a, b| a.name.cmp(&b.name));
        if !module.is_empty() {
            for seg in &module {
                api.push_str(&format!("namespace {} {{\n", sanitize_ident(seg)));
            }
        }

        let mut by_impl: BTreeMap<String, Vec<FnDef>> = BTreeMap::new();
        let mut free = Vec::new();
        for f in funcs {
            if f.kind == "free" {
                free.push(f);
            } else if let Some(imp) = f.impl_name.clone() {
                by_impl.entry(imp).or_default().push(f);
            }
        }

        for (imp, mut fns) in by_impl {
            fns.sort_by(|a, b| a.name.cmp(&b.name));
            let struct_name = if fns.iter().any(|f| f.kind == "trait") {
                sanitize_ident(&imp)
            } else {
                format!("{}Api", sanitize_ident(&imp))
            };
            let current_ns = if module.is_empty() {
                crate_info.ns_root.join("::")
            } else {
                format!("{}::{}", crate_info.ns_root.join("::"), module.join("::"))
            };
            let fallback_self_ty = if current_ns.is_empty() {
                sanitize_ident(&imp)
            } else {
                format!("{}::{}", current_ns, sanitize_ident(&imp))
            };
            let self_ty = fns
                .iter()
                .find_map(|f| {
                    f.impl_self_ty.as_ref().and_then(|ty| {
                        type_to_cpp(
                            ty,
                            &crate_info.ns_root[0],
                            &current_ns,
                            &[],
                            &f.use_map,
                            None,
                        )
                    })
                })
                .unwrap_or(fallback_self_ty);
            api.push_str(&format!("struct {} {{\n", struct_name));
            for f in fns {
                let sig = &f.sig;
                let generics = generics_params(&sig.generics);
                if !generics.is_empty() {
                    api.push_str("  template <");
                    let params: Vec<String> =
                        generics.iter().map(|g| format!("typename {}", g)).collect();
                    api.push_str(&params.join(", "));
                    api.push_str(">\n");
                }

                let ret = match &sig.output {
                    ReturnType::Default => "void".to_string(),
                    ReturnType::Type(_, ty) => {
                        if is_unit_type(ty) {
                            "void".to_string()
                        } else {
                            type_to_cpp(
                                ty,
                                &crate_info.ns_root[0],
                                &current_ns,
                                &generics,
                                &f.use_map,
                                Some(self_ty.as_str()),
                            )
                            .unwrap_or_else(|| "void*".to_string())
                        }
                    }
                };

                let mut params: Vec<String> = Vec::new();
                let mut param_names: Vec<String> = Vec::new();
                for arg in &sig.inputs {
                    match arg {
                        FnArg::Receiver(r) => {
                            let is_const = r.reference.is_some() && r.mutability.is_none();
                            let ty = if is_const {
                                format!("const {}*", self_ty)
                            } else {
                                format!("{}*", self_ty)
                            };
                            params.push(format!("{} self", ty));
                            param_names.push("self".to_string());
                        }
                        FnArg::Typed(t) => {
                            let name = match &*t.pat {
                                syn::Pat::Ident(id) => sanitize_ident(&id.ident.to_string()),
                                _ => "arg".to_string(),
                            };
                            let ty = type_to_cpp(
                                &t.ty,
                                &crate_info.ns_root[0],
                                &current_ns,
                                &generics,
                                &f.use_map,
                                Some(self_ty.as_str()),
                            )
                            .unwrap_or_else(|| "void*".to_string());
                            params.push(format!("{} {}", ty, name));
                            param_names.push(name);
                        }
                    }
                }

                let body = emit_body(&f.pattern, &f.rva, &ret, &param_names);
                api.push_str(&format!(
                    "  static {} {}({}) {{ {} }}\n",
                    ret,
                    sanitize_ident(&f.name),
                    params.join(", "),
                    body
                ));
            }
            api.push_str("};\n\n");
        }

        for f in free {
            let sig = &f.sig;
            let generics = generics_params(&sig.generics);
            if !generics.is_empty() {
                api.push_str("template <");
                let params: Vec<String> =
                    generics.iter().map(|g| format!("typename {}", g)).collect();
                api.push_str(&params.join(", "));
                api.push_str(">\n");
            }
            let current_ns = if module.is_empty() {
                crate_info.ns_root.join("::")
            } else {
                format!("{}::{}", crate_info.ns_root.join("::"), module.join("::"))
            };
            let ret = match &sig.output {
                ReturnType::Default => "void".to_string(),
                ReturnType::Type(_, ty) => {
                    if is_unit_type(ty) {
                        "void".to_string()
                    } else {
                        type_to_cpp(
                            ty,
                            &crate_info.ns_root[0],
                            &current_ns,
                            &generics,
                            &f.use_map,
                            None,
                        )
                        .unwrap_or_else(|| "void*".to_string())
                    }
                }
            };
            let mut params: Vec<String> = Vec::new();
            let mut param_names: Vec<String> = Vec::new();
            for arg in &sig.inputs {
                if let FnArg::Typed(t) = arg {
                    let name = match &*t.pat {
                        syn::Pat::Ident(id) => sanitize_ident(&id.ident.to_string()),
                        _ => "arg".to_string(),
                    };
                    let ty = type_to_cpp(
                        &t.ty,
                        &crate_info.ns_root[0],
                        &current_ns,
                        &generics,
                        &f.use_map,
                        None,
                    )
                    .unwrap_or_else(|| "void*".to_string());
                    params.push(format!("{} {}", ty, name));
                    param_names.push(name);
                }
            }
            let body = emit_body(&f.pattern, &f.rva, &ret, &param_names);
            api.push_str(&format!(
                "inline {} {}({}) {{ {} }}\n",
                ret,
                sanitize_ident(&f.name),
                params.join(", "),
                body
            ));
        }

        if !module.is_empty() {
            for _ in &module {
                api.push_str("}\n");
            }
        }
        api.push('\n');
    }

    api.push_str("}} // namespace eldenring::api\n");

    fs::write(args.out.join("api.hpp"), api)?;
    fs::write(args.report, report)?;
    write_api_runtime(&args.out, &args.fsrs)?;

    Ok(())
}
