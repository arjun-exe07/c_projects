#include <stdio.h>

// Helper function to flush the input buffer completely
void clear_buffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

float celsiusToFahrenheit(float c) { return (c * 9.0 / 5.0) + 32; }
float fahrenheitToCelsius(float f) { return (f - 32) * 5.0 / 9.0; }
float kmToMiles(float km) { return km * 0.621371; }
float milesToKm(float miles) { return miles * 1.60934; }
float kgToPounds(float kg) { return kg * 2.20462; }
float poundsToKg(float pounds) { return pounds * 0.453592; }
int main()
{
  int choice = 0;
  float value;

  while (choice != 7)
  {
    printf("\n===== Secure Unit Converter =====\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");
    printf("5. Kilograms to Pounds\n");
    printf("6. Pounds to Kilograms\n");
    printf("7. Exit\n");

    printf("\nEnter your choice: ");
    if (scanf("%d", &choice) != 1)
    {
      printf("[!] Invalid choice. Please enter digits only.\n");
      clear_buffer();
      continue;
    }
    clear_buffer(); // Clean trailing newlines

    if (choice == 7)
    {
      printf("Thank you for using Unit Converter.\n");
      break;
    }

    if (choice < 1 || choice > 7)
    {
      printf("[!] Invalid choice. Select 1-7.\n");
      continue;
    }

    // Safe Input Loop for the conversion value
    for (;;)
    {
      printf("Enter value to convert: ");
      if (scanf("%f", &value) != 1)
      {
        printf("[!] Invalid numeric data type entered.\n");
        clear_buffer();
        continue;
      }
      clear_buffer(); // Clean trailing characters

      // --- Context-Aware Domain Validation ---
      int isValid = 1;

      switch (choice)
      {
      case 1: // Celsius
        if (value < -273.15f)
        {
          printf("[!] Error: Value below Absolute Zero (-273.15°C).\n");
          isValid = 0;
        }
        break;
      case 2: // Fahrenheit
        if (value < -459.67f)
        {
          printf("[!] Error: Value below Absolute Zero (-459.67°F).\n");
          isValid = 0;
        }
        break;
      case 3: // Distances and Weights cannot be negative
      case 4:
      case 5:
      case 6:
        if (value < 0.0f)
        {
          printf("[!] Error: Distance or weight measurements cannot be negative.\n");
          isValid = 0;
        }
        break;
      }

      if (isValid)
        break; // Input passed security profiles, exit the validation loop
    }

    // --- Safe Calculation Execution ---
    switch (choice)
    {
    case 1:
      printf("\n%.2f °C = %.2f °F\n", value, celsiusToFahrenheit(value));
      break;
    case 2:
      printf("\n%.2f °F = %.2f °C\n", value, fahrenheitToCelsius(value));
      break;
    case 3:
      printf("\n%.2f km = %.2f miles\n", value, kmToMiles(value));
      break;
    case 4:
      printf("\n%.2f miles = %.2f km\n", value, milesToKm(value));
      break;
    case 5:
      printf("\n%.2f kg = %.2f pounds\n", value, kgToPounds(value));
      break;
    case 6:
      printf("\n%.2f pounds = %.2f kg\n", value, poundsToKg(value));
      break;
    }
  }

  return 0;
}