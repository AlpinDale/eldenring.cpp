#!/usr/bin/env bash
set -euo pipefail

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
fsrs="$root/third_party/fromsoftware-rs"

while [[ $# -gt 0 ]]; do
  case "$1" in
    --fsrs)
      fsrs="$2"
      shift 2
      ;;
    *)
      echo "Unknown argument: $1" >&2
      exit 1
      ;;
  esac
done

input="$fsrs/tools/param-generator/params/eldenring"
output="$fsrs/crates/eldenring/src/param/generated.rs"

if [[ ! -d "$input" ]]; then
  echo "Paramdef input not found: $input" >&2
  exit 1
fi

echo "Using fromsoftware-rs: $fsrs"
echo "Input: $input"
echo "Output: $output"

(cd "$fsrs" && cargo run --bin param-generator -- --input "$input" --output "$output")

if command -v rustfmt >/dev/null 2>&1; then
  rustfmt --edition 2021 "$output"
else
  echo "rustfmt not found on PATH; generated.rs not formatted." >&2
fi
