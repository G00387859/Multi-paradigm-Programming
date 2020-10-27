#include <stdio.h>
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

int main(){
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
    int arr = [];
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
            printf("Name of Product %s PRICE %.2f QUANTITY %d\n", name,price,quantity);
        }
    }
}
