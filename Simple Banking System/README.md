# Banking System in C (V3 - File Handling Edition)

A simple console-based banking system written in C. This project demonstrates:

- Structures and pointers
- Menu-driven programming
- Input validation
- Binary file handling for data persistence

## Features

- Create a bank account with name, account number, and balance
- Deposit money
- Withdraw money with balance validation
- View account details
- Automatic data saving using a binary file
- Load existing account data at startup

## Concepts Used

- `struct`
- Pointers
- Functions
- Menu-driven control flow
- Input validation
- File handling with `fopen()`, `fread()`, `fwrite()`, and `fclose()`

## File Handling

The account data is stored in a binary file named `account.dat`.

- On program start: load account data if `account.dat` exists
- On exit: save account data automatically

## How It Works

1. The program starts
2. It checks whether `account.dat` exists
3. If the file exists, account data is loaded
4. If the file does not exist, a new account is created
5. The user can choose to deposit, withdraw, or view account details
6. On exit, the account data is stored in `account.dat`

## Sample Menu

```text
1. Deposit
2. Withdraw
3. Check Account Details
4. Exit
```

## How to Run

Compile the program using GCC:

```bash
gcc main.c -o banking
```

Run the compiled executable:

```bash
./banking
```

## Project Structure

```
Simple Banking System/
├── main.c
├── account.dat   (auto-generated)
└── README.md
```

## Learning Outcome

This project helps to understand:

- Real-world use of `struct`
- Pointer-based function design
- File persistence (saving and loading data)
- Basic system design thinking

## Future Improvements (V4 Ideas)

- Support multiple accounts
- Add login with account number and PIN
- Add transaction history logging
- Improve security validation
- Use a database-style storage system

## Author

Arjun Kadam
