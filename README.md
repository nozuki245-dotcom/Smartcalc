# SmartCalc (C++17)

SmartCalc is a console calculator that runs in a loop and supports:
- `+` addition
- `-` subtraction
- `*` multiplication
- `/` division (with division-by-zero protection)
- `^` exponentiation (using `pow()`)

The program asks for:
1. first number
2. operator
3. second number

After each calculation, it asks: `Continue? (y/n)`.

## Requirements

- A C++ compiler with C++17 support (`g++`, `clang++`, or MSVC `cl`)

## Build and Run

### Windows (PowerShell)

#### Option A: Using g++
```powershell
g++ -std=c++17 -O2 -o smartcalc.exe main.cpp
.\smartcalc.exe
```

#### Option B: Using MSVC (Developer Command Prompt)
```bat
cl /EHsc /std:c++17 main.cpp
main.exe
```

### Linux / macOS
```bash
g++ -std=c++17 -O2 -o smartcalc main.cpp
./smartcalc
```

## Notes

- If `g++` is not recognized, install a C++ toolchain and reopen terminal.
- Output is formatted with 2 decimal places for readability.
