#include <stdio.h>

// Helper function to clear malicious or broken data from the input buffer
void clear_buffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ; // EOF means end of file
}
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
    printf("Enter the non-zero second number :");

    while (scanf("%f", &num2) != 1)
    {
      printf("Invalid data type entered.\n");
      clear_buffer();
      num2 = 0; // Force loop to stay active
    }
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
    if (scanf("%d", &ch) != 1)
    {
      printf("\n[!] Error: Please enter numeric digits only.\n\n");
      clear_buffer(); // Discard the broken input strings
      continue;
    }

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
    while (scanf("%f", &num1) != 1)
    {
      printf("[!] Invalid input. Enter a valid number: ");
      clear_buffer();
    }

    printf("Enter second number :");
    while (scanf("%f", &num2) != 1)
    {
      printf("[!] Invalid input. Enter a valid number: ");
      clear_buffer();
    }

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