$executable = "java"
$classpath = "-cp"
$classpathValue = "src"
$mainClass = "Main"

# Each hashtable contains 'input' and 'expectedOutput'
$testCases = @(
    @{
        'input' = @("justmiroslav")
        'expectedOutput' = "Welcome, justmiroslav!"
    },
    @{
        'input' = @("justmiroslav")
        'expectedOutput' = "Hello again(x1), justmiroslav"
    },
    @{
        'input' = @("justmiroslav", "delete")
        'expectedOutput' = $null
    },
    @{
        'input' = @("bread")
        'expectedOutput' = $null
    },
    @{
        'input' = @()
        'expectedOutput' = "Error: Incorrect number of arguments."
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