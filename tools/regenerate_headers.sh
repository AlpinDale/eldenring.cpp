#!/usr/bin/env bash
set -euo pipefail

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
fsrs="${1:-$root/third_party/fromsoftware-rs}"
out="${2:-$root/include/eldenring}"

if ! command -v cargo >/dev/null 2>&1; then
  echo "cargo not found on PATH. Install Rust or update PATH." >&2
  exit 1
fi

echo "Using fromsoftware-rs: $fsrs"
echo "Output dir: $out"
cd "$root/tools/generate"
cargo run --release --bin eldenring_cpp_gen -- --fsrs "$fsrs" --out "$out"
cargo run --release --bin api_gen -- --fsrs "$fsrs" --out "$out" --report "$root/api_parity_report.md"
