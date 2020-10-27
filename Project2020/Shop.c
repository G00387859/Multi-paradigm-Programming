#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	int index;
};

struct Customer {
	char* name;
	double budget;
	struct ProductStock shoppingList[10];
	int index;
};

void printProduct(struct Product p)
{
	printf("PRODUCT NAME: %s \nPRODUCT PRICE: %.2f\n", p.name, p.price);
	//printf("-------------\n");
}

void printCustomer(struct Customer c)
{
	printf("CUSTOMER NAME: %s \nCUSTOMER BUDGET: %.2f\n", c.name, c.budget);
	for(int i = 0; i < c.index; i++)
	{
		printProduct(c.shoppingList[i].product);
		printf("%s ORDERS %d OF ABOVE PRODUCT\n", c.name, c.shoppingList[i].quantity);
		double cost = c.shoppingList[i].quantity * c.shoppingList[i].product.price;
		printf("The cost to %s will be €%.2f\n", c.name, cost);
	}
}

struct Shop createAndStockShop()
{
	struct Shop shop = { 200 };
    FILE *fp;
    //char *line = NULL;
    size_t len = 0;
    //ssize_t read;

    fp = fopen("stock.csv", "r");
    if (fp == NULL)
        exit(1);
    //new code
    char line[200];
    while(fgets(line,sizeof(line),fp)) {
        char *token;
        token = strtok(line,"");
       while(token != NULL){
            token = strtok(NULL, ",");
            char *n = strtok(line,",");
           // printf("------n%s ",n);
            char *p = strtok(NULL,",");
            char *q = strtok(NULL,",");
            char *name = malloc(sizeof(char)* 50);
            strcpy(name, n);
            int quantity = atoi(q);
            double price = atof(p);
            struct Product product = {name,price};
            struct ProductStock stockItem = {product, quantity};
            shop.stock[shop.index++]= stockItem;
            //printf("Name of Product %s PRICE %.2f QUANTITY %d\n", name,price,quantity);
        }
    }

	return shop;
}
// this method will print the stock of the shop.
void printShop(struct Shop s)
{
	printf("Shop has %.2f in cash\n", s.cash);
	for (int i = 0; i < s.index; i++)
	{
		printProduct(s.stock[i].product);
		printf("The shop has %d of the above\n", s.stock[i].quantity);
		printf("-------------\n");
	}
}

int main(void)
{
    //the customer
	//struct Customer dominic = { "Dominic", 100.0 };
	//
	//struct Product coke = { "Can Coke", 1.10 };
	//struct Product bread = { "Bread", 0.7 };
	// // printProduct(coke);
	//
    //struct ProductStock cokeStock = { coke, 20 };
	//struct ProductStock breadStock = { bread, 2 };
	//
	//dominic.shoppingList[dominic.index++] = cokeStock;
	//dominic.shoppingList[dominic.index++] = breadStock;
	//
	//printCustomer(dominic);

	struct Shop shop = createAndStockShop();
	printShop(shop);

// printf("The shop has %d of the product %s\n", cokeStock.quantity, cokeStock.product.name);

    return 0;
}
