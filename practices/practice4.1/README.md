## Commands for compiling and testing the code

### Compiling the code for program
```bash
    clang++ -std=c++23 -Iinclude src\*.cpp main.cpp -o <output_file>
```

### Compiling the code for testing
```bash
    clang++ -std=c++23 -Iinclude -Itest/include src/*.cpp test/src/*.cpp -o <output_file>
```

### Testing/Running the code
```bash
    <output_file>
```