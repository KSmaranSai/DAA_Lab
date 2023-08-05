#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * intFile = fopen("IntArray.txt","w+");
    if (intFile == NULL)
    {
        printf("The file is not opened. The program will now exit.");
        exit(0);
    }
    else
    {
        printf("File Opened successfully.\n");
    }
    for (int i = 0; i < 1000; i++)
    {
        putw(rand()%10,intFile);
    }
    printf("Updated File \"IntArray.txt\"");
    fclose(intFile);
return 0;
}