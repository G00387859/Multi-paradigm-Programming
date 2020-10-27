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
int checkStock(struct Shop s)
{
    for(int i =0; i < s.index; i++){
        if(s.stock[i].quantity <= 0){
            return 1;
        }
        return 2;
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
int checkCustomersBudget(struct Customer c, int cost)
{
    if( cost > c.budget)
    {
        //print: not enought money mate.
        return 1;
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
//Read bulk orders
void readBulkOrders()
{
    //read the csv.
    //check that the budget is greater that the cost .
    // create the shopping list.

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
            printf("-------------\n");
            printf("Shop has %.2f in cash\n", shop.cash);
            int checkstock = checkStock(shop);
            printShop(shop);
            if(checkstock == 1)
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
                //struct Customer dominic = { cName[i], cBudget[i] };
                struct ProductStock cokeStock = {shop.stock[0].product, coke};
                //Bread
                struct ProductStock breadOrder = {shop.stock[1].product, bread};
                //Spaghetti
                //old way : struct ProductStock spaghettiOrder = {Spaghetti, 1};
                struct ProductStock spaghettiOrder = {shop.stock[2].product, spag};
                //decreaseStock(shop,2,1);
                //Tomato Sauce
                struct ProductStock SauceOrder = {shop.stock[3].product, sauce};
                struct ProductStock binBagOrder = {shop.stock[4].product, binBags};

                dominic.shoppingList[dominic.index++] = cokeStock;

                // printf("Remaining Coke Stock is %d\n", cokeRem);
                dominic.shoppingList[dominic.index++] = breadOrder;
                //printf("Remaining Bread Stock is %d\n", breadRem);
                dominic.shoppingList[dominic.index++] = spaghettiOrder;

                //printf("Remaining spaghetti Stock is %d\n", spaghRem);
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
            if(checkstock == 2)
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
            //char *fileNames[5] = {"bulkOrder.csv"};
            shop = createAndStockShop(cash);
            printf("-------------\n");
            printf("Shop has %.2f in cash\n", shop.cash);
            //int checkStock =
            printShop(shop);
//            if(checkStock == 1)
//            {
                char *custName = "Donal";
                double budget = 100.0;
                double quantitys[20];
                int cokeRem;
                int breadRem;
                int spaghRem;
                int SauceRem;
                int binBagRem;
                int quantity;
                double price;
                struct Customer customer;
                //struct Product product;
                struct ProductStock stockItem;
                FILE *fp;
                //char *line = NULL;
                size_t len = 0;
                //ssize_t read;
                //char *fileName = fileNames[0];
                fp = fopen("bulkOrder.csv", "r");
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
                    int i =0;
                    while(token != NULL)
                    {
                        token = strtok(NULL, ",");
                        char *n = strtok(line,",");
                        // printf("------n%s ",n);
                        char *p = strtok(NULL,",");
                        char *q = strtok(NULL,",");
                        char *name = malloc(sizeof(char)* 50);
                        strcpy(name, n);
                        quantity = atoi(q);
                        quantitys[i] = atoi(q);
                        price = atof(p);
                        i++;
                    }
                }

                struct Customer dominic = { custName, budget};
                //struct Customer dominic = { cName[i], cBudget[i] };
                struct ProductStock cokeStock = {shop.stock[0].product,quantitys[0]};
                //Bread
                struct ProductStock breadOrder = {shop.stock[1].product, quantitys[1]};
                //Spaghetti
                //old way : struct ProductStock spaghettiOrder = {Spaghetti, 1};
                struct ProductStock spaghettiOrder = {shop.stock[2].product, quantitys[2]};
                //decreaseStock(shop,2,1);
                //Tomato Sauce
                struct ProductStock SauceOrder = {shop.stock[3].product, quantitys[3]};
                struct ProductStock binBagOrder = {shop.stock[4].product, quantitys[4]};

                dominic.shoppingList[dominic.index++] = cokeStock;

                // printf("Remaining Coke Stock is %d\n", cokeRem);
                dominic.shoppingList[dominic.index++] = breadOrder;
                //printf("Remaining Bread Stock is %d\n", breadRem);
                dominic.shoppingList[dominic.index++] = spaghettiOrder;

                //printf("Remaining spaghetti Stock is %d\n", spaghRem);
                dominic.shoppingList[dominic.index++] = SauceOrder;
                dominic.shoppingList[dominic.index++] = binBagOrder;
                cost = printCustomer(dominic);
                cash = cash + cost;
                printf("The cost will be €%.2f\n", cost);
                if(budget > cost)
                {
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
                    printf("Not enought money/n");
                }


            //}
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
        i++;
    }
//return 0;

}
