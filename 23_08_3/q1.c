#include <stdio.h>
#include <stdlib.h>

void convertToBinary(int num,int* a, int i)
{
	// Base condition
	if(i==16){
		return;
	}
    
    a[15-i] = num%2;
	convertToBinary(num/2,a,i+1);
}

int main(int argc, char *argv[])
{
	// Declaration
	int n = atoi(argv[1]);
	FILE *f_input = fopen(argv[2], "r");
	FILE *f_output = fopen(argv[3], "w");

	// Opening File
	if (f_input == NULL)
	{
		printf("%s is not opened. The program will "
			   "exit now\n",
			   argv[2]);
		exit(0);
	}
	else
	{
		printf("%s is opened Successfully.\n", argv[2]);
	}

	if (f_output == NULL)
	{
		printf("%s is not opened. The program will "
			   "exit now\n",
			   argv[3]);
		exit(0);
	}
	else
	{
		printf("%s is opened Successfully.\n", argv[3]);
	}

	// storing values from input file to array
	int *num = (int *)malloc(n * sizeof(int));
	printf("\nElements are : \n");
	for (int i = 0; i < n && !feof(f_input); i++)
	{
		fscanf(f_input, "%d", &num[i]);
		printf("%d\n", num[i]);
	}

	int **binary = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++)
	{
		binary[i] = (int *)malloc(16 * sizeof(int));
	}

	for (int i = 0; i < n; i++)
	{
		convertToBinary(num[i],binary[i],0);
	}

	for (int i = 0; i < n; i++)
	{
		fprintf(f_output,"The binary equivalent of %d is : ",num[i]);
		for (int j = 0; j < 16; j++)
		{
			fprintf(f_output,"%d",binary[i][j]);
		}
		fprintf(f_output,"\n");
	}

	fclose(f_input);
    fclose(f_output);
	printf("\nBinary values written on %s successfully !!\n",argv[3]);

	return 0;
}
