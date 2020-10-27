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
    //printf("-------------\n");
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
    //printf("The cost will be €%.2f\n", cost);
    return cost;
}

struct Shop createAndStockShop()
{
    struct Shop shop = { 200 };
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
double printShop(struct Shop s)
{
    printf("-------------\n");
    printf("Shop has %.2f in cash\n", s.cash);
    for (int i = 0; i < s.index; i++)
    {
        printf("-------------\n");
        printProduct(s.stock[i].product);
        printf("The shop has %d of the above\n", s.stock[i].quantity);
        printf("-------------\n");
    }

}
//update the stock method takes the shop, the index of the product quanitiy and the order
//if the order j is greater than the current stock say sorry when have only got this!
void decreaseStock(struct Shop s, int x, int j)
{
    int quantitys = s.stock[x].quantity ;
    s.stock[x].quantity = s.stock[x].quantity - j;
    //quantitys = s.stock[x].quantity ;
    //printf("***in decreaseStock method the quantitys is %d ****\n",quantitys);
    if(j > quantitys)
    {
        printf("Sorry your order %d is greater that our current stock\n",j);
        printf("Our current stock of ordered product is %d\n ", quantitys );
    }
    else
    {
        //int remainStock = quantitys - j;
        printf("The shop had %d of the above\n", quantitys);
        printf("The shop now has %d of the above\n", s.stock[x].quantity );
    }
}
char getProductName(struct Product p)
{

    return p.name;
}
int checkCustomersBudget(struct Customer c, struct Product p )
{
    if(c.budget < p.price)
    {
        //print: not enought money mate.
        return 1;
    }
    else
    {
        return 2;
    }
}
void writeToFile(struct Shop s, int c, int b,int sp, int sc )
//writeToFile(shop,cokeRem,breadRem,spaghRem,SauceRem);
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
    //system("pause");
}
void createCustomer(struct Customer c){
    char name = c.name;
    int budget = c.index;
// name
// budget
// call createAndStockShop
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

    struct Shop shop = createAndStockShop();
    int choice = 1;
    int num1;
    while( choice = 1)
    {
        printf("Enter a number:\n1 for shop customers\n2 for bulk orders\nOr 3 to exit: ");
        scanf("%d", &num1);
        //printf("num1:%d",num1);

        if(num1 == 1)
        {
            int cust =1;
            int num2;
            //create loop for more customers
            while(cust == 1){
            printf("Press 1 for new Customer\nOr 0 to exit shop:");
            scanf("%d", &num2);
            char *name;
            int budget;
            if(num2 == 1){
            //printf()
            printShop(shop);
            printf("\n\n");
            printf("Enter you name:");
            scanf("%s", &name);
            printf("Enter your budget:");
            scanf("%d", &budget);

            struct Customer dominic = { name, budget };
            //the customer orders
            struct ProductStock cokeStock = {shop.stock[0].product, 20};
            //Bread
            struct ProductStock breadOrder = {shop.stock[1].product, 2};
            //old way: struct ProductStock breadOrder = {bread, 2};
            //decreaseStock(shop,1,2);
            //Spaghetti
            //old way : struct ProductStock spaghettiOrder = {Spaghetti, 1};
            struct ProductStock spaghettiOrder = {shop.stock[2].product, 1};
            //Tomato Sauce
            struct ProductStock SauceOrder = {shop.stock[3].product, 1};

            dominic.shoppingList[dominic.index++] = cokeStock;
            int cokeRem =  shop.stock[0].quantity - 20;
            printf("Remaining Coke Stock is %d\n", cokeRem);
            dominic.shoppingList[dominic.index++] = breadOrder;
            int breadRem =  shop.stock[2].quantity - 1;
            printf("Remaining Bread Stock is %d\n", breadRem);
            dominic.shoppingList[dominic.index++] = spaghettiOrder;
            int spaghRem =  shop.stock[3].quantity - 1;
            printf("Remaining spaghetti Stock is %d\n", spaghRem);
            dominic.shoppingList[dominic.index++] = SauceOrder;
            int SauceRem =  shop.stock[4].quantity - 1;
            printf("Remaining Sauce Stock is %d\n", SauceRem);
            //checkShoppingList
            double cost = printCustomer(dominic);
            shop.cash += cost;
            printf("The cost will be €%.2f\n", cost);
            printf("The shop cash is now will be €%.2f\n", shop.cash);
            writeToFile(shop,cokeRem,breadRem,spaghRem,SauceRem);
            }
            }
        }
        if(num1 == 2)
        {
            printf("bulk");
        }
        if(num1 == 3)
        {
            printf("game over");
            break;
        }
       // else
        //{
        //    exit(1);
      //  }
    }
    //return 0;

}
