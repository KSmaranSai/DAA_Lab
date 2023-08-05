#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * intFile = fopen("input.dat","w");
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
        fprintf(intFile,"%d\n",(rand()%100)+1);
    }
    printf("Updated File \"input.dat.txt\"");
    fclose(intFile);
return 0;
}