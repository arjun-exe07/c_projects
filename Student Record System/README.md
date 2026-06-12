# Student Record System

A menu-driven Student Record Management System written in C. The program allows users to add, update, delete, search, and display student records. Records are stored in a binary file, enabling data persistence between program executions.

## Features

* Add Student
* Update Student Information
* Delete Student
* Search Student by Roll Number
* Display All Students
* Prevent Duplicate Roll Numbers
* Save Records to File
* Load Records from File

## Concepts Used

* Structures
* Arrays of Structures
* Functions
* Pointers
* File Handling
* Binary Files (`fread`, `fwrite`)
* CRUD Operations
* Linear Search

## Project Structure

```text
C-Projects/
│
├── Number_Guessing_Game/
├── Unit_Converter/
├── Banking_System/
├── Student_Record_System/
│   ├── main.c
│   ├── README.md
│   └── record.dat
│
└── Library_Management_System/
```

## Student Structure

```c
struct Student
{
    int rollNo;
    char name[50];
    float marks;
};
```

## Menu Options

```text
1. Add Student
2. Update Student Info
3. Delete Student Info
4. Display All Students
5. Search Student
6. Exit
```

## Learning Outcomes

Through this project, I practiced:

* Managing records using structures
* Passing arrays and pointers to functions
* Implementing CRUD operations
* Searching records using linear search
* Using binary file handling for persistent storage
* Organizing a menu-driven application

## Build and Run

```bash
gcc main.c -o student_record_system
./student_record_system
```
