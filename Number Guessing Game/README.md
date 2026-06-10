# Number Guessing Game

A simple console-based Number Guessing Game built using the C programming language.

## Features

* Generates a random number between 1 and 100
* Accepts user guesses
* Displays hints:

  * Too High
  * Too Low
* Counts the number of attempts
* Validates input range (1-100)
* Ends when the correct number is guessed

## Concepts Used

* Variables and Data Types
* Conditional Statements (`if-else`)
* Loops (`for`)
* Random Number Generation (`rand()`)
* Random Seed (`srand()`)
* Time Library (`time.h`)
* User Input (`scanf()`)

## How to Run

### Compile

```bash
gcc main.c -o game
```

### Execute

```bash
./game
```

## Sample Output

```text
Enter your guess from 1 to 100 : 50
Too High

Enter your guess from 1 to 100 : 25
Too Low

Enter your guess from 1 to 100 : 37
Win

Congratulations! You took 3 attempts.
```

## Learning Outcomes

Through this project, I learned:

* How pseudo-random number generation works in C
* The purpose of `rand()` and `srand()`
* How to use `time(NULL)` as a seed
* Implementing game logic using loops and conditions
* Tracking user attempts

## Author

Arjun Kadam
