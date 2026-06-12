#include <stdio.h>
#define MAX_SUBJECTS 50

void clear_buffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

char calculateGrade(float average)
{
  if (average >= 90)
    return 'A';
  else if (average >= 80)
    return 'B';
  else if (average >= 70)
    return 'C';
  else if (average >= 60)
    return 'D';
  else
    return 'F';
}

int main()
{
  int subjects = 0;

  for (;;)
  {
    printf("Enter number of subjects (1 to %d): ", MAX_SUBJECTS);
    if (scanf("%d", &subjects) != 1)
    {
      printf("[!] Invalid input. Please enter numeric digits only.\n\n");
      clear_buffer();
      continue;
    }
    clear_buffer(); // Clean trailing newlines

    if (subjects > 0 && subjects <= MAX_SUBJECTS)
    {
      break; // Valid input, escape loop safely
    }
    else
    {
      printf("[!] Out of bounds. Please enter a value between 1 and %d.\n\n", MAX_SUBJECTS);
    }
  }

  int marks[MAX_SUBJECTS];
  int total = 0;

  for (int i = 0; i < subjects; i++)
  {
    for (;;)
    {
      printf("Enter marks for Subject %d (0-100): ", i + 1);
      if (scanf("%d", &marks[i]) != 1)
      {
        printf("[!] Invalid input. Enter numbers only.\n");
        clear_buffer();
        continue;
      }
      clear_buffer(); // Clean trailing characters
      if (marks[i] >= 0 && marks[i] <= 100)
      {
        break; // Valid marks value entered
      }
      else
      {
        printf("[!] Out of scope. Marks must be between 0 and 100.\n");
      }
    }
    total += marks[i];
  }

  float average = (float)total / subjects;
  char grade = calculateGrade(average);

  printf("\n===== Result =====\n");
  printf("Total Marks : %d\n", total);
  printf("Average     : %.2f\n", average);
  printf("Grade       : %c\n", grade);

  return 0;
}