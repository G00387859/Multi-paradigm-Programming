#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void error_handling()
{
    int errnum;
    errnum = errno;
    fprintf(stderr, "Value of errno: %d\n", errno);
    //perror("Error printed by perror");
    //fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
}
//int basket(stock){

//return 0;
//}
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
int main(void)
{
    int cokeStock = 40;
    int number;
    int loopVar =1;
    printf("Welcome to the Shop\n");
    //printf("Enter 1 for standard customer\nEnter 2 for bulk orders\nEnter 0 to exit:");
    while(loopVar == 1)
    {
        //printf("Enter an integer: ");
        printf("Enter 1 for standard customer\nEnter 2 for bulk orders\nEnter 0 to exit:\n");
        number = 1;
        // reads and stores input
        scanf("%d", &number);
        // displays output
        //printf("You entered: %d", number);
        printf("number: %d\n", number);
        if(number == 1)
        {
            int selection1 = 0;
            while(selection1 == 0)
            {
                int products;
                int quanity;
                printf("Ok lets shop\n");
                printf("Shopping today\nPress 1 for Coke\nPress 2 for cereal\nPress 3 for smokes:\nPress 0 to Proceed to checkout\n");
                scanf("%d", &products);
                if(products == 1)
                {
                    //method here like CustomerOrders(stock,products){return remaining stock}
                    // products = 1 , 2 , 3;
                    // 1 = coke,  2 = cereal, 3 = smokes
                    printf("We have %d coke in stock", cokeStock);
                    printf("How many would you like?:\n ");
                    scanf("%d", &quanity);
                    //call the stock method
                    printf("products %d\n",products);
                    printf("quanity %d\n ",quanity);

                }
                if(products == 0){
                    break;
                }

            }

        }

        if(number == 2)
        {
            printf("In second");
        }
        if(number == 0)
        {
            break;
        }

    }
    return 0;
}
