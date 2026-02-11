#!/usr/bin/env bash
set -euo pipefail

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
fsrs="$root/third_party/fromsoftware-rs"
ww_exe=""
jp_exe=""
ww_only=0

while [[ $# -gt 0 ]]; do
  case "$1" in
    --fsrs)
      fsrs="$2"
      shift 2
      ;;
    --ww-exe)
      ww_exe="$2"
      shift 2
      ;;
    --jp-exe)
      jp_exe="$2"
      shift 2
      ;;
    --ww-only)
      ww_only=1
      shift 1
      ;;
    *)
      echo "Unknown argument: $1" >&2
      exit 1
      ;;
  esac
done

if [[ -z "$ww_exe" ]]; then
  ww_exe="${MAPPER_ER_WW_EXE:-}"
fi
if [[ -z "$jp_exe" ]]; then
  jp_exe="${MAPPER_ER_JP_EXE:-}"
fi

echo "Using fromsoftware-rs: $fsrs"
if [[ "$ww_only" -eq 1 ]]; then
  if [[ -z "$ww_exe" ]]; then
    echo "Missing WW exe path. Pass --ww-exe or set MAPPER_ER_WW_EXE." >&2
    exit 1
  fi
  echo "WW-only mode. JP RVAs will not be updated."
  echo "WW exe: $ww_exe"
  out_path="$fsrs/crates/eldenring/src/rva/rva_ww.rs"
  (cd "$fsrs" && cargo run --bin binary-mapper -- map --profile crates/eldenring/mapper-profile.toml --exe "$ww_exe" --output rust > "$out_path")
else
  if [[ -z "$ww_exe" || -z "$jp_exe" ]]; then
    echo "Missing exe paths. Pass --ww-exe/--jp-exe or set MAPPER_ER_WW_EXE and MAPPER_ER_JP_EXE." >&2
    exit 1
  fi
  echo "WW exe: $ww_exe"
  echo "JP exe: $jp_exe"
  (cd "$fsrs" && cargo run --bin binary-mapper -- er --ww-exe "$ww_exe" --jp-exe "$jp_exe" --project-root "$fsrs")
fi
