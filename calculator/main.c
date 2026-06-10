#include <stdio.h>

float add(float num1, float num2)
{
  // sum function
  return num1 + num2;
}

float subtract(float num1, float num2)
{
  // difference function
  return num1 - num2;
}

float multiply(float num1, float num2)
{
  // multiplication function
  return num1 * num2;
}

float divide(float num1, float num2)
{
  // divsion function
  while (num2 == 0)
  {
    printf("A Number cannot be divided by zero\n");
    printf("Enter the second number :");
    scanf("%f", &num2);
  }
  return num1 / num2;
}

// main function
int main()
{

  int ch = 0;
  float num1, num2, result;
  printf("==== Calculator ====\n\n\n");

  while (ch != 5)
  {
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n\n");

    printf("Enter your choice :");
    scanf("%d", &ch);

    if (ch == 5)
    {
      printf("\nTHANKS FOR USING CALCULATOR");
      break;
    }
    if (ch < 1 || ch > 5)
    {
      printf("\nInvalid choice\n\n\n");
      continue;
    }
    printf("\nEnter first number :");
    scanf("%f", &num1);
    printf("Enter second number :");
    scanf("%f", &num2);

    switch (ch)
    {
    case 1:
      result = add(num1, num2);
      printf("\n%.2f + %.2f = %.2f\n\n\n", num1, num2, result);
      break;

    case 2:
      result = subtract(num1, num2);
      printf("\n%.2f - %.2f = %.2f\n\n\n", num1, num2, result);
      break;

    case 3:
      result = multiply(num1, num2);
      printf("\n%.2f * %.2f = %.2f\n\n\n", num1, num2, result);
      break;

    case 4:
      result = divide(num1, num2);
      printf("\n%.2f / %.2f = %.2f\n\n\n", num1, num2, result);
      break;
    }
  }

  return 0;
}