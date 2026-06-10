#include <stdio.h>

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
  int subjects;

  do
  {
    printf("Enter number of subjects: ");
    scanf("%d", &subjects);
  } while (subjects <= 0);

  int marks[subjects];
  int total = 0;

  for (int i = 0; i < subjects; i++)
  {
    do
    {
      printf("Enter marks for Subject %d (0-100): ", i + 1);
      scanf("%d", &marks[i]);
    } while (marks[i] < 0 || marks[i] > 100);

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