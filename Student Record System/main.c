#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

void clear_buffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

struct Student
{
  int rollNo;
  char name[50];
  float marks;
};

void addStudent(struct Student students[], int *count)
{
  if (*count >= MAX_STUDENTS)
  {
    printf("Student list is full.\n");
    return;
  }
  int roll;
  for (;;)
  {
    printf("Enter Roll No. (Positive Integer): ");
    if (scanf("%d", &roll) != 1)
    {
      printf("[!] Invalid type. Please enter digits only.\n");
      clear_buffer();
      continue;
    }
    clear_buffer();

    if (roll <= 0)
    {
      printf("[!] Roll number must be greater than zero.\n");
      continue;
    }

    // Verify uniqueness
    int duplicate = 0;
    for (int i = 0; i < *count; i++)
    {
      if (roll == students[i].rollNo)
      {
        duplicate = 1;
        break;
      }
    }

    if (duplicate)
    {
      printf("[!] Roll number already exists in database.\n");
      return; // Exit out to main menu
    }
    break; // Roll validation passed
  }
  students[*count].rollNo = roll;

  printf("Enter Name :");
  getchar();
  fgets(students[*count].name, 50, stdin);
  // can use  strcspn(str1, str2) to remove \n

  printf("Enter marks :");
  scanf("%f", &students[*count].marks);

  (*count)++;
}

void updateStudent(struct Student students[], int count)
{
  int roll;
  int found = 0;

  if (count == 0)
  {
    printf("No students available.\n");
    return;
  }

  printf("Enter Roll No. to update: ");
  scanf("%d", &roll);

  for (int i = 0; i < count; i++)
  {
    if (students[i].rollNo == roll)
    {
      printf("\nStudent Found\n");

      printf("Enter New Name: ");
      getchar();
      fgets(students[i].name, 50, stdin); // This stores \n after getting input so formatting is not proper

      printf("Enter New Marks: ");
      scanf("%f", &students[i].marks);

      printf("Record Updated Successfully.\n");

      found = 1;
      break;
    }
  }

  if (!found)
  {
    printf("Student not found.\n");
  }
}

void deleteStudent(struct Student students[], int *count)
{
  int roll;
  int found = 0;

  if (*count == 0)
  {
    printf("No students available.\n");
    return;
  }

  printf("Enter Roll No. to delete: ");
  scanf("%d", &roll);

  for (int i = 0; i < *count; i++)
  {
    if (students[i].rollNo == roll)
    {
      for (int j = i; j < *count - 1; j++)
      {
        students[j] = students[j + 1];
      }

      (*count)--;

      printf("Student deleted successfully.\n");

      found = 1;
      break;
    }
  }

  if (!found)
  {
    printf("Student not found.\n");
  }
}

void displayStudents(struct Student students[], int count)
{
  printf("\n--- Student Details ---\n");
  if (count == 0)
  {
    printf("No students found.\n");
    return;
  }

  for (int i = 0; i < count; i++)
  {
    printf("\nStudent #%d\n", i + 1);
    printf("Roll No. : %d\n", students[i].rollNo);
    printf("Name : %s\n", students[i].name);
    printf("Marks : %.2f\n", students[i].marks);
  }
}

void searchStudent(struct Student students[], int count)
{
  int roll;
  int flag = 0;
  printf("Enter Roll No. to search :");
  scanf("%d", &roll);

  if (count == 0)
  {
    printf("No students available.\n");
    return;
  }

  for (int i = 0; i < count; i++)
  {
    if (roll == students[i].rollNo)
    {
      printf("%d Roll number found\n", roll);
      printf("Roll No. : %d\n", students[i].rollNo);
      printf("Name : %s\n", students[i].name);
      printf("Marks : %.2f\n", students[i].marks);
      flag = 1;
      break;
    }
  }
  if (flag == 0)
  {
    printf("%d Roll number Not found\n", roll);
  }
}

void saveStudent(struct Student students[], int count)
{
  FILE *fp = fopen("record.dat", "wb");

  if (fp == NULL)
  {
    printf("Error opening file\n");
    return;
  }
  fwrite(&count, sizeof(int), 1, fp); // The file is being written in binary.

  fwrite(students, sizeof(struct Student), count, fp);
  fclose(fp);
}

int loadStudent(struct Student students[], int *count)
{

  FILE *fp = fopen("record.dat", "rb");

  if (fp == NULL)
    return 0; // no record exist

  fread(count, sizeof(int), 1, fp);
  fread(students, sizeof(struct Student), *count, fp);

  fclose(fp);
  return 1;
}
int main()
{

  struct Student students[100];
  int count = 0, ch;
  int exists = 0;

  exists = loadStudent(students, &count);

  for (;;)
  {
    printf("1. Add Student\n");
    printf("2. Update a Student Info\n");
    printf("3. Delete a Student Info\n");
    printf("4. Display All Students\n");
    printf("5. Search Student\n");
    printf("6. Exit\n");

    printf("\nEnter your choice :");
    scanf("%d", &ch);

    if (ch == 6)
    {
      saveStudent(students, count);
      printf("\nStudent Record saved successfully.\n");
      printf("\nThanks for using Student Record system.\n");
      break;
    }

    switch (ch)
    {
    case 1:
    {
      addStudent(students, &count);
      // saveStudent(students, count);
      break;
    }

    case 2:
    {
      updateStudent(students, count);
      // saveStudent(students, count);
      break;
    }

    case 3:
    {
      deleteStudent(students, &count);
      // saveStudent(students, count);
      break;
    }

    case 4:
    {
      displayStudents(students, count);
      break;
    }

    case 5:
    {
      searchStudent(students, count);
      break;
    }

    default:
      printf("Invalid choice\n");
    }
  }

  return 0;
}