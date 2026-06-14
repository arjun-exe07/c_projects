#include <stdio.h>

struct account
{
  char name[50];
  int account_Number;
  float balance;
};

void deposit(struct account *Acc)
{
  float amount = 0;
  while (amount <= 0)
  {
    printf("\n\nEnter the amount to deposit :");
    scanf("%f", &amount);
    if (amount <= 0)
      printf("The amount must be greater than zero");
  }
  Acc->balance += amount;
}

void withdraw(struct account *Acc)
{
  float amount = 0;
  while (amount <= 0)
  {
    printf("\n\nEnter the amount to withdraw :");
    scanf("%f", &amount);
    if (amount <= 0)
      printf("The amount must be greater than zero");
  }
  if (amount <= Acc->balance)
    Acc->balance -= amount;

  else
    printf("Insufficient Balance !!\n");
}

void viewAccountDetails(struct account *Acc)
{
  printf("Name        : %s\n", Acc->name);
  printf("Account No. : %d\n", Acc->account_Number);
  printf("Balance     : %.2f\n", Acc->balance);
}

void saveAccount(struct account *acc)
{
  FILE *fp = fopen("account.dat", "wb");

  if (fp == NULL)
  {
    printf("Error opening file\n");
    return;
  }

  fwrite(acc, sizeof(struct account), 1, fp);

  fclose(fp);
}

int loadAccount(struct account *acc)
{
  FILE *fp = fopen("account.dat", "rb");

  if (fp == NULL)
  {
    return 0; // no account exists
  }

  fread(acc, sizeof(struct account), 1, fp);

  fclose(fp);
  return 1; // success
}
int main()
{

  struct account Acc;
  int ch;
  printf("=== Simple Banking System ===\n\n\n");
  int exists = loadAccount(&Acc);

  if (!exists)
  {
    printf("Enter Account Holder Name: ");

    fgets(Acc.name, 50, stdin);
    getchar(); // clears leftover newline
    Acc.account_Number = 0;
    while ((Acc.account_Number) <= 0)
    {
      printf("Enter Account Number: ");
      scanf("%d", &Acc.account_Number);
      if (Acc.account_Number <= 0)
        printf("Enter correct Account number\n");
    }

    Acc.balance = 0.0;
    while ((Acc.balance) <= 0)
    {
      printf("Enter Account Initial Balance: ");
      scanf("%f", &Acc.balance);
      if (Acc.balance < 0)
        printf("The initial balance cannot be negative\n");
    }
  }
  for (;;)
  {
    printf("1. Deposit\n");
    printf("2. WithDraw\n");
    printf("3. Check Account Details\n");
    printf("4. Exit\n");

    printf("\nEnter your choice");
    scanf("%d", &ch);

    if (ch == 4)
    {
      saveAccount(&Acc);
      printf("\nAccount saved successfully.\n");
      printf("\nThanks for using banking system.\n");
      break;
    }
    switch (ch)
    {
    case 1:
    {
      deposit(&Acc);
      saveAccount(&Acc);
      break;
    }

    case 2:
    {
      withdraw(&Acc);
      saveAccount(&Acc); // saves after every transaction
      break;
    }

    case 3:
    {
      viewAccountDetails(&Acc);
      break;
    }

    default:
      printf("Invalid choice\n");
    }
  }
}