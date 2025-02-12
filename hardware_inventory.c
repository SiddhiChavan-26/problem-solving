#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int itemID;
    char itemName[50];
    int piecesOrdered;
    int piecesInStore;
    int piecesSold;
    float manufacturerPrice;
    float sellingPrice;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount < MAX_ITEMS) {
        printf("Enter item ID: ");
        scanf("%d", &inventory[itemCount].itemID);
        printf("Enter item name: ");
        scanf("%s", inventory[itemCount].itemName);
        printf("Enter number of pieces ordered: ");
        scanf("%d", &inventory[itemCount].piecesOrdered);
        inventory[itemCount].piecesInStore = inventory[itemCount].piecesOrdered;
        inventory[itemCount].piecesSold = 0;
        printf("Enter manufacturer's price: ");
        scanf("%f", &inventory[itemCount].manufacturerPrice);
        printf("Enter store's selling price: ");
        scanf("%f", &inventory[itemCount].sellingPrice);
        
        itemCount++;
    } else {
        printf("Inventory is full!\n");
    }
}

void sellItem() {
    int id, quantity, i;
    printf("Enter item ID to sell: ");
    scanf("%d", &id);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);

    for (i = 0; i < itemCount; i++) {
        if (inventory[i].itemID == id) {
            if (inventory[i].piecesInStore >= quantity) {
                inventory[i].piecesInStore -= quantity;
                inventory[i].piecesSold += quantity;
                printf("Item sold successfully!\n");
            } else {
                printf("Not enough pieces in store!\n");
            }
            return;
        }
    }
    printf("Item not found!\n");
}

void generateReport() {
	int i;
    printf("\nWeekly Report:\n");
    printf("ID\tName\tOrdered\tIn Store\tSold\tMan. Price\tSell Price\n");
    for ( i = 0; i < itemCount; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%.2f\t%.2f\n", inventory[i].itemID, inventory[i].itemName, inventory[i].piecesOrdered, inventory[i].piecesInStore, inventory[i].piecesSold, inventory[i].manufacturerPrice, inventory[i].sellingPrice);
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Add Item\n");
        printf("2. Sell Item\n");
        printf("3. Generate Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                sellItem();
                break;
            case 3:
                generateReport();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
