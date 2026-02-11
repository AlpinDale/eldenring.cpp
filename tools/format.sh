#!/usr/bin/env bash
set -euo pipefail

root="${1:-$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)}"

if ! command -v clang-format >/dev/null 2>&1; then
  echo "clang-format not found on PATH." >&2
  exit 1
fi

cd "$root"

files=()
for dir in "$root/examples" "$root/tests"; do
  if [ -d "$dir" ]; then
    while IFS= read -r -d '' f; do
      files+=("$f")
    done < <(find "$dir" -type f \( -name '*.cpp' -o -name '*.h' -o -name '*.hpp' \) -print0)
  fi
done

filtered=("${files[@]}")

if [ ${#filtered[@]} -eq 0 ]; then
  echo "No files to format."
else
  echo "Formatting C/C++ files: ${#filtered[@]}"
  clang-format -i "${filtered[@]}"
fi

if command -v cargo >/dev/null 2>&1 && command -v rustfmt >/dev/null 2>&1; then
  manifest="$root/tools/generate/Cargo.toml"
  if [ -f "$manifest" ]; then
    echo "Running cargo fmt on $manifest"
    cargo fmt --manifest-path "$manifest"
  else
    echo "Cargo.toml not found at $manifest; skipping Rust formatting."
  fi
else
  echo "cargo or rustfmt not found; skipping Rust formatting."
fi
