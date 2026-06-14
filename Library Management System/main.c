#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_STUDENTS 50

typedef struct
{
  int rollNo;
  char name[50];
} Student;

typedef struct
{
  int bookID;
  char title[50];
  char author[50];
  int isIssued;       // 0 = Available on shelf, 1 = Checked out
  int borrowerRollNo; // Foreign Key: Links to Student->rollNo if isIssued == 1
} Book;

void clear_buffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

// Helper function to find a student index by Roll Number
int findStudentIndex(Student students[], int studentCount, int rollNo)
{
  for (int i = 0; i < studentCount; i++)
  {
    if (students[i].rollNo == rollNo)
      return i;
  }
  return -1; // Not found
}

// Helper function to find a book index by ID
int findBookIndex(Book books[], int bookCount, int bookID)
{
  for (int i = 0; i < bookCount; i++)
  {
    if (books[i].bookID == bookID)
      return i;
  }
  return -1; // Not found
}

void registerStudent(Student students[], int *studentCount)
{
  if (*studentCount >= MAX_STUDENTS)
  {
    printf("[!] Student registry is currently full.\n");
    return;
  }

  int roll;
  printf("\n--- Register New Student ---\n");
  printf("Enter Roll No: ");
  if (scanf("%d", &roll) != 1 || roll <= 0)
  {
    printf("[!] Invalid input.\n");
    clear_buffer();
    return;
  }
  clear_buffer();

  if (findStudentIndex(students, *studentCount, roll) != -1)
  {
    printf("[!] Error: This Roll Number is already registered.\n");
    return;
  }

  students[*studentCount].rollNo = roll;
  printf("Enter Student Name: ");
  fgets(students[*studentCount].name, 50, stdin);
  students[*studentCount].name[strcspn(students[*studentCount].name, "\n")] = '\0';

  (*studentCount)++;
  printf("[+] Student registered successfully.\n");
}

void addBook(Book books[], int *bookCount)
{
  if (*bookCount >= MAX_BOOKS)
  {
    printf("[!] Library inventory capacity reached.\n");
    return;
  }

  int id;
  printf("\n--- Add New Book ---\n");
  printf("Enter Unique Book ID: ");
  if (scanf("%d", &id) != 1 || id <= 0)
  {
    printf("[!] Invalid input.\n");
    clear_buffer();
    return;
  }
  clear_buffer();

  if (findBookIndex(books, *bookCount, id) != -1)
  {
    printf("[!] Error: A book with this ID already exists.\n");
    return;
  }

  books[*bookCount].bookID = id;

  printf("Enter Book Title: ");
  fgets(books[*bookCount].title, 50, stdin);
  books[*bookCount].title[strcspn(books[*bookCount].title, "\n")] = '\0';

  printf("Enter Author: ");
  fgets(books[*bookCount].author, 50, stdin);
  books[*bookCount].author[strcspn(books[*bookCount].author, "\n")] = '\0';

  books[*bookCount].isIssued = 0; // Fresh books start on the shelf
  books[*bookCount].borrowerRollNo = 0;

  (*bookCount)++;
  printf("[+] Book added to inventory successfully.\n");
}

void issueBook(Book books[], int bookCount, Student students[], int studentCount)
{
  printf("\n--- Issue Book Menu ---\n");
  int id, roll;

  printf("Enter Book ID to issue: ");
  if (scanf("%d", &id) != 1)
  {
    clear_buffer();
    return;
  }

  int bIndex = findBookIndex(books, bookCount, id);
  if (bIndex == -1)
  {
    printf("[!] Error: Book ID not found in library inventory.\n");
    return;
  }

  if (books[bIndex].isIssued == 1)
  {
    printf("[!] Operational Failure: This book is already checked out.\n");
    return;
  }

  printf("Enter Borrower Student Roll No: ");
  if (scanf("%d", &roll) != 1)
  {
    clear_buffer();
    return;
  }
  clear_buffer();

  // DEFENSIVE RULE: Verify the borrower actually exists before allowing the lease
  int sIndex = findStudentIndex(students, studentCount, roll);
  if (sIndex == -1)
  {
    printf("[!] Transaction Rejected: No student found with Roll No %d.\n", roll);
    return;
  }

  // Bind relationship securely
  books[bIndex].isIssued = 1;
  books[bIndex].borrowerRollNo = roll;
  printf("[+] Success! '%s' issued to %s.\n", books[bIndex].title, students[sIndex].name);
}

void returnBook(Book books[], int bookCount)
{
  printf("\n--- Return Book Menu ---\n");
  int id;
  printf("Enter Book ID being returned: ");
  if (scanf("%d", &id) != 1)
  {
    clear_buffer();
    return;
  }
  clear_buffer();

  int bIndex = findBookIndex(books, bookCount, id);
  if (bIndex == -1)
  {
    printf("[!] Book ID not recognized.\n");
    return;
  }

  if (books[bIndex].isIssued == 0)
  {
    printf("[*] This book is already safe on the library shelves.\n");
    return;
  }

  // Reset bindings cleanly
  books[bIndex].isIssued = 0;
  books[bIndex].borrowerRollNo = 0;
  printf("[+] Return processed successfully. Status: Available.\n");
}

void displayBooks(Book books[], int bookCount, Student students[], int studentCount)
{
  printf("\n=================================== LIBRARY CATALOG ===================================\n");
  if (bookCount == 0)
  {
    printf("The inventory is completely empty.\n");
    return;
  }

  for (int i = 0; i < bookCount; i++)
  {
    printf("ID: %-4d | Title: %-20s | Author: %-15s | Status: ",
           books[i].bookID, books[i].title, books[i].author);

    if (books[i].isIssued == 0)
    {
      printf("AVAILABLE\n");
    }
    else
    {
      // Relational live look-up mapping
      int sIndex = findStudentIndex(students, studentCount, books[i].borrowerRollNo);
      if (sIndex != -1)
      {
        printf("ISSUED to %s (Roll: %d)\n", students[sIndex].name, students[sIndex].rollNo);
      }
      else
      {
        // Catches corrupted states or manually altered data files
        printf("ISSUED to [ORPHANED ID: %d]\n", books[i].borrowerRollNo);
      }
    }
  }
  printf("========================================================================================\n");
}

void saveLibrary(Book books[], int bookCount, Student students[], int studentCount)
{
  FILE *fp = fopen("library.dat", "wb");
  if (!fp)
    return;

  // Write array counting prefixes sequentially
  fwrite(&bookCount, sizeof(int), 1, fp);
  fwrite(books, sizeof(Book), bookCount, fp);

  fwrite(&studentCount, sizeof(int), 1, fp);
  fwrite(students, sizeof(Student), studentCount, fp);

  fclose(fp);
}

void loadLibrary(Book books[], int *bookCount, Student students[], int *studentCount)
{
  FILE *fp = fopen("library.dat", "rb");
  if (!fp)
    return;

  // Load and sanitize books collection boundaries
  if (fread(bookCount, sizeof(int), 1, fp) != 1 || *bookCount < 0 || *bookCount > MAX_BOOKS)
  {
    *bookCount = 0;
    fclose(fp);
    return;
  }
  fread(books, sizeof(Book), *bookCount, fp);

  // Load and sanitize students collection boundaries
  if (fread(studentCount, sizeof(int), 1, fp) != 1 || *studentCount < 0 || *studentCount > MAX_STUDENTS)
  {
    *studentCount = 0;
    *bookCount = 0;
    fclose(fp);
    return;
  }
  fread(students, sizeof(Student), *studentCount, fp);

  fclose(fp);
}

int main()
{
  Book books[MAX_BOOKS] = {0};
  Student students[MAX_STUDENTS] = {0};
  int bookCount = 0, studentCount = 0, ch = 0;

  loadLibrary(books, &bookCount, students, &studentCount);

  for (;;)
  {
    printf("\n===== Secure Relational Library System =====\n");
    printf("1. Register Student\n");
    printf("2. Add New Book\n");
    printf("3. Issue a Book\n");
    printf("4. Return a Book\n");
    printf("5. View Catalog\n");
    printf("6. Save & Exit\n");
    printf("Choice: ");

    if (scanf("%d", &ch) != 1)
    {
      printf("[!] Invalid numeric selection.\n");
      clear_buffer();
      continue;
    }
    clear_buffer();

    if (ch == 6)
    {
      saveLibrary(books, bookCount, students, studentCount);
      printf("\n[+] Database compiled and written safely to disk. Goodbye!\n");
      break;
    }

    switch (ch)
    {
    case 1:
      registerStudent(students, &studentCount);
      break;
    case 2:
      addBook(books, &bookCount);
      break;
    case 3:
      issueBook(books, bookCount, students, studentCount);
      break;
    case 4:
      returnBook(books, bookCount);
      break;
    case 5:
      displayBooks(books, bookCount, students, studentCount);
      break;
    default:
      printf("[!] Option out of scope.\n");
    }
  }
  return 0;
}