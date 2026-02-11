param(
  [string]$Root
)

$rootPath = if ($Root) { $Root } else { (Split-Path -Parent $PSScriptRoot) }

if (-not (Get-Command clang-format -ErrorAction SilentlyContinue)) {
  Write-Error "clang-format not found on PATH."
  exit 1
}

Set-Location $rootPath

$files = @()
foreach ($dir in @("examples", "tests")) {
  $path = Join-Path $rootPath $dir
  if (Test-Path $path) {
    $files += Get-ChildItem -Path $path -Recurse -Include *.cpp,*.h,*.hpp -File |
      ForEach-Object { $_.FullName }
  }
}

$files = $files | Where-Object { $_ }

if (-not $files -or $files.Count -eq 0) {
  Write-Host "No files to format."
} else {
  Write-Host ("Formatting C/C++ files: {0}" -f $files.Count)
  foreach ($file in $files) {
    & clang-format -i $file
  }
}

$cargo = Get-Command cargo -ErrorAction SilentlyContinue
$rustfmt = Get-Command rustfmt -ErrorAction SilentlyContinue
if (-not $cargo) {
  Write-Host "cargo not found; skipping Rust formatting."
} elseif (-not $rustfmt) {
  Write-Host "rustfmt not found; skipping Rust formatting."
} else {
  $manifestPath = Join-Path $rootPath "tools\\generate\\Cargo.toml"
  if (Test-Path $manifestPath) {
    Write-Host ("Running cargo fmt on {0}" -f $manifestPath)
    & cargo fmt --manifest-path $manifestPath
  } else {
    Write-Host ("Cargo.toml not found at {0}; skipping Rust formatting." -f $manifestPath)
  }
}
