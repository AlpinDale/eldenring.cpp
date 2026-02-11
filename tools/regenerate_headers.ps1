param(
  [string]$FsrsDir,
  [string]$OutDir
)

$root = Split-Path -Parent $PSScriptRoot
$fsrs = if ($FsrsDir) { $FsrsDir } else { Join-Path $root "third_party\\fromsoftware-rs" }
$out = if ($OutDir) { $OutDir } else { Join-Path $root "include\\eldenring" }
$gen = Join-Path $root "tools\\generate"

if (-not (Get-Command cargo -ErrorAction SilentlyContinue)) {
  Write-Error "cargo not found on PATH. Install Rust or update PATH."
  exit 1
}

Write-Host "Using fromsoftware-rs: $fsrs"
Write-Host "Output dir: $out"
Push-Location $gen
try {
  cargo run --release -- --fsrs $fsrs --out $out
} finally {
  Pop-Location
}
