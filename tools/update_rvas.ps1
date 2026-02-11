param(
  [string]$WwExe,
  [string]$JpExe,
  [string]$FsrsDir,
  [switch]$WwOnly
)

$root = Split-Path -Parent $PSScriptRoot
$fsrs = if ($FsrsDir) { $FsrsDir } else { Join-Path $root "third_party\\fromsoftware-rs" }

if (-not (Get-Command cargo -ErrorAction SilentlyContinue)) {
  Write-Error "cargo not found on PATH. Install Rust or update PATH."
  exit 1
}

if (-not $WwExe) { $WwExe = $env:MAPPER_ER_WW_EXE }
if (-not $JpExe) { $JpExe = $env:MAPPER_ER_JP_EXE }

Write-Host "Using fromsoftware-rs: $fsrs"

Push-Location $fsrs
try {
  if ($WwOnly) {
    if (-not $WwExe) {
      Write-Error "Missing WW exe path. Pass -WwExe or set MAPPER_ER_WW_EXE."
      exit 1
    }
    Write-Host "WW-only mode. JP RVAs will not be updated."
    Write-Host "WW exe: $WwExe"
    $outPath = Join-Path $fsrs "crates\\eldenring\\src\\rva\\rva_ww.rs"
    $content = & cargo run --bin binary-mapper -- map --profile "crates\\eldenring\\mapper-profile.toml" --exe $WwExe --output rust
    if ($LASTEXITCODE -ne 0) {
      exit $LASTEXITCODE
    }
    $joined = ($content -join [Environment]::NewLine)
    [System.IO.File]::WriteAllText($outPath, $joined, [System.Text.UTF8Encoding]::new($false))
  } else {
    if (-not $WwExe -or -not $JpExe) {
      Write-Error "Missing exe paths. Pass -WwExe/-JpExe or set MAPPER_ER_WW_EXE and MAPPER_ER_JP_EXE."
      exit 1
    }
    Write-Host "WW exe: $WwExe"
    Write-Host "JP exe: $JpExe"
    cargo run --bin binary-mapper -- er --ww-exe $WwExe --jp-exe $JpExe --project-root $fsrs
  }
} finally {
  Pop-Location
}
