$executable = "java"
$classpath = "-cp"
$classpathValue = "src"
$mainClass = "Main"

# Each hashtable contains 'input' and 'expectedOutput'
$testCases = @(
    @{
        'input' = @("image.txt", "blue")
        'expectedOutput' = "Usage: java Main <input_filename> <output_filename> <favorite_color> [<unfavorite_color>]"
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
        'input' = @("invalidPixels.txt", "output.txt", "red")
        'expectedOutput' = "Invalid pixel in line 3"
    },
    @{
        'input' = @("invalidPixelsAmount.txt", "output.txt", "red")
        'expectedOutput' = "Invalid amount of pixels in line 3"
    },
    @{
        'input' = @("invalidLinesAmount.txt", "output.txt", "red")
        'expectedOutput' = "Invalid amount of lines in file"
    },
    @{
        'input' = @("image.txt", "output.txt", "blue", "nonExistentUnfavoriteColor")
        'expectedOutput' = "Unfavorite color not found"
    },
    @{
        'input' = @("image.txt", "output.txt", "blue")
        'expectedOutput' = "Favorite color has been successfully expanded"
    }
)

foreach ($testCase in $testCases) {
    # Run the executable with the test case input
    $output = & $executable $classpath $classpathValue $mainClass $testCase.input

    # Compare the output with the expected output
    if ($output -eq $testCase.expectedOutput) {
        Write-Host "Test passed for input: $($testCase.input)"
    } else {
        Write-Host "Test failed for input: $($testCase.input)"
        Write-Host "Expected: $($testCase.expectedOutput)"
        Write-Host "Got: $output"
    }
}
