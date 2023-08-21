#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[50];
    int num = 0;
    printf("Enter Name of file : ");
    scanf("%s", filename);
    FILE *intFile = fopen(filename, "w");
    if (intFile == NULL)
    {
        printf("The file is not opened. The program will now exit.");
        exit(0);
    }
    else
    {
        printf("File Opened successfully.\n");
    }
    for (int i = 0; i < 500; i++)
    {
        // fprintf(intFile,"%d\n",(rand()%100)+1);
        fprintf(intFile, "%d\n", num);
        num = num + 10;
    }
    printf("Updated File \"%s\"", filename);
    fclose(intFile);
    return 0;
}