param (
    [Parameter(Mandatory=$true)][string]$source_file1,
    [Parameter(Mandatory=$true)][string]$source_file2,
    [Parameter(Mandatory=$true)][string]$output_file
)

if ($source_file -eq "" -or $output_file -eq "") {
    Write-Host "Usage: .\scripts\compile.ps1 <source_file1> <source_file2> -o <output_file>"
    exit 1
}

& 'clang++' -Wall -Wextra -Wpedantic -Werror -std=c++23 -Iinclude $source_file1 $source_file2 -o $output_file