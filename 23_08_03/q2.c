#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main(int argc, char *argv[])
{
	// Declaration
	FILE *f_input = fopen(argv[1], "r");
	FILE *f_output = fopen(argv[2], "w");

	// Opening File
	if (f_input == NULL)
	{
		printf("%s is not opened. The program will "
			   "exit now\n",
			   argv[1]);
		exit(0);
	}
	else
	{
		printf("%s is opened Successfully.\n", argv[1]);
	}

	if (f_output == NULL)
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

	// storing values from input file to array
    int a,b;
    for (int i = 0; i < 40; i=i+2)
    {
        fscanf(f_input, "%d%d", &a,&b);
        fprintf(f_output,"The GCD of %d and %d is %d\n",a,b,gcd(a,b));
    }
    
    fclose(f_input);
    fclose(f_output);
	printf("\nGCD of 2 numbers written on %s successfully !!\n",argv[2]);

	return 0;
}
