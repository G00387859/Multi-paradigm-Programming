#include <stdio.h>

int main(){
    FILE *the_file = fopen("stock.csv","r");
    if(the_file ==NULL){
        perror("Unable to open the file");
        exit(1);
    }
    char line[220];

    while(fgets(line, sizeof(line), the_file)){
        char *token;


        token = strtok(line, ",");

        while(token != NULL){
                printf("%-18s",token);
                token = strtok(NULL,",");

        }
        printf("\n");
    }
}
