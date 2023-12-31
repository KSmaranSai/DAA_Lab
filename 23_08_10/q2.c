#include <stdio.h>
#include <stdlib.h>

void insertionSort(int array[], int n, int *comparisons)
{
    for (int i = 1; i < n; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            (*comparisons)++;
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void printArrayToFile(FILE *output, int array[], int n)
{
    if (output == NULL)
    {
        printf("Error opening file");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(output, "%d ", array[i]);
    }

    fclose(output);
}

void printArrayWithComparisons(int array[], int n, int comparisons)
{
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\nNumber of Comparisons: %d\n", comparisons);

    if (comparisons == 0)
    {
        printf("Input scenario is best case.\n");
    }
    else if (comparisons == (n * (n - 1)) / 2)
    {
        printf("Input scenario is worst case.\n");
    }
    else
    {
        printf("Input scenario is average case.\n");
    }
}

int main()
{
    int option, n = 0;
    int array[500];
    int comparisons = 0;
    FILE *input;
    FILE *output;

    printf("MAIN MENU (INSERTION SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. Exit\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
    {
        input = fopen("inAsce.dat", "r");
        output = fopen("outInsAsce.dat", "w");
        break;
    }
    case 2:
    {
        input = fopen("inDesc.dat", "r");
        output = fopen("outInsDesc.dat", "w");
        break;
    }
    case 3:
    {
        input = fopen("inRand.dat", "r");
        output = fopen("outInsRand.dat", "w");
        break;
    }
    case 4:
        exit(0);
    default:
        printf("Invalid option. Please select a valid option.\n");
    }


    while (fscanf(input, "%d", &array[n]) == 1)
    {
        n++;
    }

    fclose(input);
    insertionSort(array, n, &comparisons);
    printArrayToFile(output, array, n);
    printArrayWithComparisons(array, n, comparisons);

    return 0;
}