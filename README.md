# C Projects

This repository contains beginner-friendly C programming projects built to practice fundamental concepts like loops, conditionals, functions, structures, file handling, and user interaction.

## Projects Included

- `Calculator/` - Menu-driven calculator for basic arithmetic operations.
- `Inventory Management System/` - Inventory tracker with file persistence.
- `Number Guessing Game/` - Interactive random number guessing game.
- `Simple Banking System/` - Bank account management with binary file storage.
- `Student Grade Calculator/` - Grade calculator based on subject marks.
- `Student Record System/` - Student record CRUD system with file persistence.
- `Unit Converter/` - Unit conversion utilities for temperature, distance, and weight.

## How to Use

Each project is self-contained in its own folder and can be compiled with a C compiler like GCC.

### Example compilation

```bash
cd "Calculator"
gcc main.c -o calculator
./calculator
```

Replace `Calculator` with any project folder to compile and run that project.

## Project Summaries

### Calculator
A simple menu-driven calculator supporting addition, subtraction, multiplication, division, and division-by-zero validation.

### Inventory Management System
A console inventory app that adds, displays, searches, sells, and restocks products. Data is saved to `inventory.dat` so product records persist across runs.

### Number Guessing Game
A game that generates a random number from 1 to 100, accepts guesses, gives high/low hints, and counts attempts.

### Simple Banking System
A basic bank account manager demonstrating structures, pointers, menu-driven logic, and binary file handling for saving account data.

### Student Grade Calculator
A grade calculator that accepts marks for multiple subjects, computes total and average, and assigns a grade based on the result.

### Student Record System
A student record management system with add, update, delete, display, and search operations. Records are stored in a binary file for persistence.

### Unit Converter
A unit conversion utility supporting:
- Celsius ↔ Fahrenheit
- Kilometers ↔ Miles
- Kilograms ↔ Pounds

## Learning Outcomes

These projects help you learn:

- C syntax and program structure
- Working with user input and console output
- Control flow using loops and conditionals
- Functions and modular code organization
- Structures and arrays
- Basic file handling with binary files
- Simple menu-driven program design

## Notes

- Each project typically compiles using `gcc main.c -o <output-name>`.
- Some projects create binary data files such as `account.dat` and `inventory.dat` for persistence.
- The source for each project is in its respective folder.

## Author

Arjun Kadam