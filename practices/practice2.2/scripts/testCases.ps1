$executable = "./program.exe"

# Each hashtable contains 'input' and 'expectedOutput'
$testCases = @(
    @{
        'input' = @("image.txt", "blue")
        'expectedOutput' = "Usage: ./program.exe <input_filename> <output_filename> <color_name>"
    },
    @{
        'input' = @("image.txt", "output.txt", "nonExistentColor")
        'expectedOutput' = "Color not found"
    },
    @{
        'input' = @("nonExistentFile.txt", "output.txt", "red")
        'expectedOutput' = "Error opening file nonExistentFile.txt"
    },
    @{
        'input' = @("invalidLinesAmount.txt", "output.txt", "red")
        'expectedOutput' = "Invalid amount of lines in file"
    },
    @{
        'input' = @("image.txt", "output.txt", "blue")
        'expectedOutput' = "Favorite color has been successfully expanded"
    }
)

foreach ($testCase in $testCases) {
    # Run the executable with the test case input
    $output = & $executable $testCase.input

    # Compare the output with the expected output
    if ($output -eq $testCase.expectedOutput) {
        Write-Host "Test passed for input: $($testCase.input)"
    } else {
        Write-Host "Test failed for input: $($testCase.input)"
        Write-Host "Expected: $($testCase.expectedOutput)"
        Write-Host "Got: $output"
    }
}
