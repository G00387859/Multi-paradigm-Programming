#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Product
{
    char* name;
    double price;
};

struct ProductStock
{
    struct Product product;
    int quantity;
};

struct Shop
{
    double cash;
    struct ProductStock stock[20];
    int index;
};

struct Customer
{
    char* name;
    double budget;
    struct ProductStock shoppingList[10];
    int index;
};


void printProduct(struct Product p)
{
    printf("PRODUCT NAME: %s \nPRODUCT PRICE: %.2f\n", p.name, p.price);
}
void printProductName(struct ProductStock p)
{
    printf("%d",p.quantity);
}
double printCustomer(struct Customer c)
{
    printf("CUSTOMER NAME: %s \nCUSTOMER BUDGET: %.2f\n", c.name, c.budget);
    double cost;
    for(int i = 0; i < c.index; i++)
    {
        printProduct(c.shoppingList[i].product);
        printf("%s ORDERS %d OF ABOVE PRODUCT\n", c.name, c.shoppingList[i].quantity);
        cost += c.shoppingList[i].quantity * c.shoppingList[i].product.price;
        printf("The cost to %s will be €%.2f\n", c.name, cost);
    }
    return cost;
}

struct Shop createAndStockShop(int c)
{
    struct Shop shop = { c };
    FILE *fp;
    //char *line = NULL;
    size_t len = 0;
    //ssize_t read;

    fp = fopen("stock.csv", "r");
    //added Dm
    //char
    //
    if (fp == NULL)
        exit(1);
    //new code
    char line[200];
    while(fgets(line,sizeof(line),fp))
    {
        char *token;
        token = strtok(line,"");
        while(token != NULL)
        {
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
    for (int i = 0; i < s.index; i++)
    {
        if(s.stock[i].quantity > 0)
        {
            printf("-------------\n");
            printProduct(s.stock[i].product);
            printf("The shop has %d of the above\n", s.stock[i].quantity);
            printf("-------------\n");
        }
        else
        {
            printf("--------------\n");
            printProduct(s.stock[i].product);
            printf("The shop has 0 of the above\n");
            printf("-------------\n");

        }
    }

}
int checkStockLevels(struct Shop s){
    int lowStock = 2;
    for(int i =0;i<s.index;i++){
        int stockCount = s.stock[i].quantity;
        printf("stockCount is %d\n", stockCount);
        if(stockCount <= 0){
                printf("Sorry out of stock\n");
            lowStock = 1;
        }
    }
    return lowStock;

}
int checkCustomersBudget(struct Customer c, int cost)
{
    if( cost > c.budget)
    {
        return 1;
    }
}
void writeToFile(struct Shop s, int c, int b,int sp, int sc )
{
// name         price   quanitiy arrayPosition
// Coke Can	     1.1	   100    0
// Bread	     0.7	   30     1
// Spaghetti	 1.2	   100    2
// Tomato Sauce	 0.8	   100    3
// Bin Bags	     2.5	   4      4
    //int quantitys;
    //int quantitys = s.stock[x].quantity;
    //int remainStock = quantitys - j;
    int CCs = c;
    int Bs = b;
    int Ss = sp;
    int TSs = sc;
    int BBs = s.stock[4].quantity;
    FILE *fp;
    fp = fopen("stock.csv","w");
    if(fp == NULL)
    {
        printf("file writing has gone wrong");
    }
    fprintf(fp,"Coke Can, %f, %d\nBread, %f, %d\nSpaghetti, %f, %d\nTomato Sauce, %f, %d\nBin Bags, %f, %d\n",1.1,CCs,0.7,Bs,1.2,Ss,0.8,TSs,2.5,BBs);
    fclose(fp);
    fp=0;
}


int main(void)
{
// name         price   quanitiy arrayPosition
// Coke Can	     1.1	   100    0
// Bread	     0.7	   30     1
// Spaghetti	 1.2	   100    2
// Tomato Sauce	 0.8	   100    3
// Bin Bags	     2.5	   4      4

    printf("--------------------------------------------------\n");
    printf("-------- Welcome to the corner store -------------\n\n");
    printf("---------current stock-----------------------------\n");


    int choice = 1;
    int num1;
    int i=0;
    double cost;
    double cash = 200;
    struct Shop shop;
    char *cName = {"Donal", "Mary", "Sean","Amy"};
    //double cBudget = {50.0,200.0,75.0,92.0};

    while( choice = 1)
    {

        printf("Enter a number:\n1 for shop customers\n2 for bulk orders\nOr 3 to exit: ");
        scanf("%d", &num1);

        // standard Customer.
        if(num1 == 1)
        {
            shop = createAndStockShop(cash);
            printShop(shop);
            printf("-------------\n");
            printf("Shop has %.2f in cash\n", shop.cash);
            int checkStock = checkStockLevels(shop);
            printf("checkStock is %d\n",checkStock);
            if(checkStock != 1)
            {
                char *custName = "Donal";
                double budget = 100.0;
                int coke = 20;
                int bread= 2;
                int spag = 1;
                int sauce = 1;
                int binBags= 1;
                int cokeRem;
                int breadRem;
                int spaghRem;
                int SauceRem;
                int binBagRem;
                struct Customer dominic = { custName, budget };
                struct ProductStock cokeStock = {shop.stock[0].product, coke};
                struct ProductStock breadOrder = {shop.stock[1].product, bread};
                struct ProductStock spaghettiOrder = {shop.stock[2].product, spag};
                struct ProductStock SauceOrder = {shop.stock[3].product, sauce};
                struct ProductStock binBagOrder = {shop.stock[4].product, binBags};

                dominic.shoppingList[dominic.index++] = cokeStock;
                dominic.shoppingList[dominic.index++] = breadOrder;
                dominic.shoppingList[dominic.index++] = spaghettiOrder;
                dominic.shoppingList[dominic.index++] = SauceOrder;
                dominic.shoppingList[dominic.index++] = binBagOrder;
                cost = printCustomer(dominic);
                cash = cash + cost;
                printf("The cost will be €%.2f\n", cost);
                if(budget > cost)
                {
                    cokeRem =  shop.stock[0].quantity - coke;
                    breadRem =  shop.stock[2].quantity - bread;
                    spaghRem =  shop.stock[3].quantity - spag;
                    SauceRem =  shop.stock[4].quantity - sauce;
                    binBagRem =  shop.stock[5].quantity - binBags;
                    printf("The shop cash is now will be €%.2f\n", cash);
                    writeToFile(shop,cokeRem,breadRem,spaghRem,SauceRem);

                }
                else
                {
                    printf("Not enought money/n");
                }
            }
            if(checkStock == 1)
            {
                printf("\n\n");
                char *custName = "Donal";
                double budget = 100.0;
                int cokeRem;
                int breadRem;
                int spaghRem;
                int SauceRem;
                int binBagRem;
            }
        }
        // bulk orders
        if(num1 == 2)
        {
            shop = createAndStockShop(cash);
            printShop(shop);
            printf("-------------\n");
            printf("Shop has %.2f in cash\n", shop.cash);
            int checkStock = checkStockLevels(shop);
            printf("checkStock is %d\n",checkStock);
            if(checkStock != 1)
            {
                char *custName = "Donal";
                double budget = 100.0;
                int quantitys[20];
                int cokeRem;
                int breadRem;
                int spaghRem;
                int SauceRem;
                int binBagRem;
                int quantity;
                double price;
                struct Customer customer;
                struct ProductStock stockItem;
                FILE *fp;
                size_t len = 0;
                fp = fopen("bulkOrder.csv", "r");
                if (fp == NULL)
                    exit(1);
                char line[200];
                int j = 0;
                while(fgets(line,sizeof(line),fp))
                {
                    char *token;
                    token = strtok(line,"");
                    while(token != NULL)
                    {

                        //printf("i %d",i);
                        token = strtok(NULL, ",");
                        char *n = strtok(line,",");
                        // printf("------n%s ",n);
                        char *p = strtok(NULL,",");
                        char *q = strtok(NULL,",");
                        char *name = malloc(sizeof(char)* 50);
                        strcpy(name, n);
                        quantity = atoi(q);
                        quantitys[j] = atoi(q);
                        price = atof(p);

                        j = j + 1;
                    }
                }
                struct Customer dominic = { custName, budget};
                struct ProductStock cokeStock = {shop.stock[0].product,quantitys[0]};
                struct ProductStock breadOrder = {shop.stock[1].product, quantitys[1]};
                struct ProductStock spaghettiOrder = {shop.stock[2].product, quantitys[2]};
                struct ProductStock SauceOrder = {shop.stock[3].product, quantitys[3]};
                struct ProductStock binBagOrder = {shop.stock[4].product, quantitys[4]};

                dominic.shoppingList[dominic.index++] = cokeStock;
                dominic.shoppingList[dominic.index++] = breadOrder;
                dominic.shoppingList[dominic.index++] = spaghettiOrder;
                dominic.shoppingList[dominic.index++] = SauceOrder;
                dominic.shoppingList[dominic.index++] = binBagOrder;
                cost = printCustomer(dominic);

                printf("The cost will be €%.2f\n", cost);
                if(budget > cost)
                {
					cash = cash + cost;
                    cokeRem =  shop.stock[0].quantity - quantitys[0];
                    breadRem =  shop.stock[2].quantity - quantitys[1];
                    spaghRem =  shop.stock[3].quantity - quantitys[2];
                    SauceRem =  shop.stock[4].quantity - quantitys[3];
                    binBagRem =  shop.stock[5].quantity - quantitys[4];
                    printf("The shop cash is now will be €%.2f\n", cash);
                    writeToFile(shop,cokeRem,breadRem,spaghRem,SauceRem);

                }
                else
                {
                    printf("You do Not enought money\n");
                }
            }
        }
        if(num1 == 3)
        {
            printf("game over");
            break;
        }
        i++;
    }

}
