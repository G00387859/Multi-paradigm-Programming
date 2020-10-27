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
int main(){
    // name         price   quanitiy arrayPosition
// Coke Can	     1.1	   100    0
// Bread	     0.7	   30     1
// Spaghetti	 1.2	   100    2
// Tomato Sauce	 0.8	   100    3
// Bin Bags	     2.5	   4      4

    printf("--------------------------------------------------\n\n");
    printf("-------- Welcome to the corner store -------------\n\n");
    printf("---------current stock-----------------------------\n");

}
