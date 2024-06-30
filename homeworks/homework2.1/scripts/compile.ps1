param (
    [Parameter(Mandatory=$true)][string]$source_directory
)

if ($source_directory -eq "") {
    Write-Host "Usage: ./compile.ps1 <source_directory>"
    exit 1
}

& 'javac' "$source_directory\*.java"
