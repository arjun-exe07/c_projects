#include <stdio.h>

struct Product
{
  int productId;
  char name[50];
  float price;
  int quantity;
};

int findProduct(struct Product products[], int count, int id)
{
  for (int i = 0; i < count; i++)
  {
    if (products[i].productId == id)
      return i;
  }
  return -1;
}

/* ---------------- FILE HANDLING ---------------- */

void saveToFile(struct Product products[], int count)
{
  FILE *fp = fopen("inventory.dat", "wb");

  if (fp == NULL)
  {
    printf("Error saving file.\n");
    return;
  }

  fwrite(&count, sizeof(int), 1, fp);
  fwrite(products, sizeof(struct Product), count, fp);

  fclose(fp);
}

void loadFromFile(struct Product products[], int *count)
{
  FILE *fp = fopen("inventory.dat", "rb");

  if (fp == NULL)
  {
    *count = 0;
    return;
  }

  fread(count, sizeof(int), 1, fp);
  fread(products, sizeof(struct Product), *count, fp);

  fclose(fp);
}

/* ---------------- CORE FUNCTIONS ---------------- */

void addProduct(struct Product products[], int *count)
{
  if (*count >= 100)
  {
    printf("Inventory is full.\n");
    return;
  }

  int id;
  printf("Enter Product ID: ");
  scanf("%d", &id);

  if (findProduct(products, *count, id) != -1)
  {
    printf("Product already exists.\n");
    return;
  }

  products[*count].productId = id;

  printf("Enter Product Name: ");
  getchar();
  scanf("%[^\n]s", products[*count].name);

  do
  {
    printf("Enter Price: ");
    scanf("%f", &products[*count].price);
  } while (products[*count].price <= 0);

  do
  {
    printf("Enter Quantity: ");
    scanf("%d", &products[*count].quantity);
  } while (products[*count].quantity <= 0);

  (*count)++;
}

void displayProducts(struct Product products[], int count)
{
  if (count == 0)
  {
    printf("No products found.\n");
    return;
  }

  for (int i = 0; i < count; i++)
  {
    printf("\nID: %d | Name: %s | Price: %.2f | Qty: %d\n",
           products[i].productId,
           products[i].name,
           products[i].price,
           products[i].quantity);
  }
}

void searchProduct(struct Product products[], int count)
{
  int id;
  printf("Enter ID to search: ");
  scanf("%d", &id);

  int idx = findProduct(products, count, id);

  if (idx == -1)
  {
    printf("Not found.\n");
    return;
  }

  printf("\nFound:\n");
  printf("ID: %d\nName: %s\nPrice: %.2f\nQty: %d\n",
         products[idx].productId,
         products[idx].name,
         products[idx].price,
         products[idx].quantity);
}

void sellProduct(struct Product products[], int count)
{
  int id, qty;
  printf("Enter product ID: ");
  scanf("%d", &id);

  int idx = findProduct(products, count, id);

  if (idx == -1)
  {
    printf("Product not found.\n");
    return;
  }

  printf("Enter quantity to sell: ");
  scanf("%d", &qty);

  if (qty > products[idx].quantity)
  {
    printf("Insufficient stock.\n");
    return;
  }

  products[idx].quantity -= qty;

  printf("Sold successfully.\n");
}

void restockProduct(struct Product products[], int count)
{
  int id, qty;
  printf("Enter product ID: ");
  scanf("%d", &id);

  int idx = findProduct(products, count, id);

  if (idx == -1)
  {
    printf("Product not found.\n");
    return;
  }

  printf("Enter quantity to add: ");
  scanf("%d", &qty);

  products[idx].quantity += qty;

  printf("Stock updated.\n");
}

/* ---------------- MAIN ---------------- */

int main()
{
  struct Product products[100];
  int count = 0, ch;

  loadFromFile(products, &count);

  for (;;)
  {
    printf("\n1. Add\n2. Display\n3. Search\n4. Sell\n5. Restock\n6. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      addProduct(products, &count);
      break;
    case 2:
      displayProducts(products, count);
      break;
    case 3:
      searchProduct(products, count);
      break;
    case 4:
      sellProduct(products, count);
      break;
    case 5:
      restockProduct(products, count);
      break;

    case 6:
      saveToFile(products, count);
      printf("Saved. Exiting...\n");
      return 0;

    default:
      printf("Invalid choice\n");
    }
  }
}