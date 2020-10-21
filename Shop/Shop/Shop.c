#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <sys/types.h>
//#include <unistd.h>

struct Product {
	char* name;
	double price;
};
struct ProductStock {
	struct Product product;
	int quantity;
};
struct Shop {
	double cash;
	struct ProductStock stock[20];
};
struct Customer {
	char* name;
	double budget;
	struct ProductStock shoppingList[10];
	int index;
};
void printProduct(struct Product p) {
	//printf("-------------------------\n");
	printf("PRODUCT NAME: %s\nPRODUCT PRICE: %.2f\n", p.name, p.price);
	printf("-------------------------\n");
}

void createStockShop() {
	struct Shop shop = { 200 };
	FILE* fp;
	char* line = NULL;
	size_t len = 0;
	size_t read;
	fp = fopen("C:\\Users\\dm086_000\\OneDrive\\Documents\\Semester2\\MMP\\Repo\\Multi-paradigm-Programming\\stock.csv", "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
	while ((read = getline(&line, &len, fp)) != -1) {
		// printf("Retrieved line of length %zu:\n", read);
		printf("%s IS A LINE", line);
	}
	
}

	void printCustomer(struct Customer c) {
		//printf("-------------------------\n");
		printf("CUSTOMER NAME: %s\nCUSTOMER budget: %.2f\n", c.name, c.budget);
		printf("-------------------------\n");
		for (int i = 0; i < c.index; i++) {
			printProduct(c.shoppingList[i].product);
			printf("%s ORDERS %d of ABOVE PRODUCT \n", c.name, c.shoppingList[i].quantity);
			double cost = c.shoppingList[i].quantity * c.shoppingList[i].product.price;
			printf("The cost to %s will be $%.2f\n", c.name, cost);
		}
	}




int main(void) {
	//struct Customer dominic = { "Doninic", 100.0 };
	//struct Product bread = { "Bread", 0.7 };
	
	//struct Product coke = { "Can Coke", 1.10 };
	////struct Product bread = { "Bread", 0.7 };

	
	//struct ProductStock cokeStock = { coke,20 };
	//struct ProductStock breadStock = { bread,2 };

	//dominic.shoppingList[dominic.index++] = cokeStock;
	//dominic.shoppingList[dominic.index++] = breadStock;

	//printCustomer(dominic);
	return 0;
}