#include <stdio.h>

float celsiusToFahrenheit(float c)
{
  return (c * 9.0 / 5.0) + 32;
}

float fahrenheitToCelsius(float f)
{
  return (f - 32) * 5.0 / 9.0;
}

float kmToMiles(float km)
{
  return km * 0.621371;
}

float milesToKm(float miles)
{
  return miles * 1.60934;
}

float kgToPounds(float kg)
{
  return kg * 2.20462;
}

float poundsToKg(float pounds)
{
  return pounds * 0.453592;
}

int main()
{
  int choice = 0;
  float value;

  while (choice != 7)
  {
    printf("\n===== Unit Converter =====\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");
    printf("5. Kilograms to Pounds\n");
    printf("6. Pounds to Kilograms\n");
    printf("7. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 7)
    {
      printf("Thank you for using Unit Converter.\n");
      break;
    }

    if (choice < 1 || choice > 7)
    {
      printf("Invalid choice.\n");
      continue;
    }

    printf("Enter value: ");
    scanf("%f", &value);

    switch (choice)
    {
    case 1:
      printf("%.2f °C = %.2f °F\n",
             value, celsiusToFahrenheit(value));
      break;

    case 2:
      printf("%.2f °F = %.2f °C\n",
             value, fahrenheitToCelsius(value));
      break;

    case 3:
      printf("%.2f km = %.2f miles\n",
             value, kmToMiles(value));
      break;

    case 4:
      printf("%.2f miles = %.2f km\n",
             value, milesToKm(value));
      break;

    case 5:
      printf("%.2f kg = %.2f pounds\n",
             value, kgToPounds(value));
      break;

    case 6:
      printf("%.2f pounds = %.2f kg\n",
             value, poundsToKg(value));
      break;
    }
  }

  return 0;
}