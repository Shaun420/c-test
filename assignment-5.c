#include <stdio.h>

// Define the structure to hold information about items
struct Item {
	int itemNumber;
	char itemName[50];
	char itemCategory[20];
	int availableStock;
};

// Function to display the information of items
void displayItems(struct Item items[], int itemCount) {
	printf("\nAvailable Items:\n");
	printf("-----------------------------------\n");
	printf("| Item Number\t| Item Name\t| Item Category\t| Available Stock\t|\n");
	printf("-----------------------------------\n");
	for(int i = 0; i < itemCount; ++i) {
		printf("| %d\t\t| %s\t| %s\t| %d\t|\n", items[i].itemNumber, items[i].itemName, items[i].itemCategory, items[i].availableStock);
	}
	printf("-----------------------------------\n");
}
int main() {
	// Define an array of items
	struct Item items[] = {
		{1, "Television", "Electronics", 5},
		{2, "Bookshelf", "Furniture", 50},
		{3, "Refrigerator", "Appliances", 20},
		{4, "Air Conditioner", "Appliances", 15},
		{5, "Watch", "Accessories", 35}
	};
	// Calculate the number of items in the array
	int itemCount = sizeof(items) / sizeof(items[0]);
	// Display the available items
	displayItems(items, itemCount);
	return 0;
}
