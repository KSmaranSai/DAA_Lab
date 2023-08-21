#include <stdio.h>
#include <stdlib.h>

int main(){
    char filename[50];
    printf("Enter Name of file : ");
    scanf("%s",filename);
    FILE * intFile = fopen(filename,"w");
    if (intFile == NULL)
    {
        printf("The file is not opened. The program will now exit.");
        exit(0);
    }
    else
    {
        printf("File Opened successfully.\n");
    }
    for (int i = 0; i < 20; i++)
    {
        fprintf(intFile,"%d\n",(rand()%100)+1);
    }
    printf("Updated File \"%s\"",filename);
    fclose(intFile);
return 0;
}