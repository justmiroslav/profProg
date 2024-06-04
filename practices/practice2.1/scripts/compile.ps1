param (
    [Parameter(Mandatory=$true)][string]$source_file,
    [Parameter(Mandatory=$true)][string]$output_file
)

if ($source_file -eq "" -or $output_file -eq "") {
    Write-Host "Usage: .\scripts\compile.ps1 <source_file> -o <output_file>"
    exit 1
}

& 'clang++' -Wall -Wextra -Wpedantic -Werror -std=c++23 $source_file -o $output_file