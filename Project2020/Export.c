#include <stdio.h>
void writeToFile(){
    int CCs = 100;
    int Bs = 80;
    int Ss = 34;
    int TSs = 21;
    int BBs = 44;
    FILE *fp;
    fp = fopen("Weell.csv","w");
    if(fp == NULL){
       printf("something wrong");
        return 1;
       }
    fprintf(fp,"Coke Can, %f, %d\nBread, %f, %d\nSpaghetti, %f, %d\nTomato Sauce, %f, %d\nBin Bags, %f, %d\n",1.1,CCs,0.7,Bs,1.2,Ss,0.8,TSs,2.5,BBs);


    fclose(fp);
    fp=0;
    system("pause");
}

int main(void){
    writeToFile;
return 0;
}
