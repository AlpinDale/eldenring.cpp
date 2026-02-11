param(
  [string]$FsrsDir
)

$root = Split-Path -Parent $PSScriptRoot
$fsrs = if ($FsrsDir) { $FsrsDir } else { Join-Path $root "third_party\\fromsoftware-rs" }
$input = Join-Path $fsrs "tools\\param-generator\\params\\eldenring"
$output = Join-Path $fsrs "crates\\eldenring\\src\\param\\generated.rs"

if (-not (Get-Command cargo -ErrorAction SilentlyContinue)) {
  Write-Error "cargo not found on PATH. Install Rust or update PATH."
  exit 1
}

if (-not (Test-Path $input)) {
  Write-Error "Paramdef input not found: $input"
  exit 1
}

Write-Host "Using fromsoftware-rs: $fsrs"
Write-Host "Input: $input"
Write-Host "Output: $output"

Push-Location $fsrs
try {
  cargo run --bin param-generator -- --input $input --output $output
} finally {
  Pop-Location
}

if (Get-Command rustfmt -ErrorAction SilentlyContinue) {
  rustfmt --edition 2021 $output
} else {
  Write-Warning "rustfmt not found on PATH; generated.rs not formatted."
}
