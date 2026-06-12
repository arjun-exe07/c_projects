#include <stdio.h>
#include <stdlib.h> //rand()
#include <time.h>

void clear_buffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}
int main()
{
  srand(time(NULL)); // set seed for random number generation.
  /*
  We used srand to give seed for random otherwise it will generate same number everytime*/
  int secret = (rand() % 100) + 1; // Gives 0 to 99 then we add 1
  int attempt = 0;
  int guess;

  for (;;)
  {
    printf("Enter your guess from 1 to 100 :");

    if (scanf("%d", &guess) != 1)
    {
      printf("[!] Invalid input. Please enter digits only.\n\n");
      clear_buffer();
      continue;
    }

    clear_buffer(); // Clean up trailing newlines or extra text (like '42abc') from a valid entry
    if (guess > 0 && guess <= 100)
    {
      attempt++;
      if (guess == secret)
      {
        printf("Win\n");
        break;
      }

      else if (guess < secret)
        printf("Too Low\n");

      else
        printf("Too High\n");
    }
    else
      printf("Enter number between 1 to 100\n");
  }

  printf("Congrtulation !!! ,You took %d attempts", attempt);
  return 0;
}