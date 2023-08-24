#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int partition(int arr[], int si, int ei,int *comp)
{
    int i = si - 1;
    for (int j = si; j < ei; j++)
    {
        if (arr[j] <= arr[ei])
        {
            (*comp)++;
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    i++;
    int temp = arr[ei];
    arr[ei] = arr[i];
    arr[i] = temp;
    return i;
}

void quicksort(int arr[], int si, int ei,int *comp)
{
    if (si >= ei)
    {
        return;
    }
    int p_index = partition(arr, si, ei,comp);
    quicksort(arr, si, p_index - 1,comp);
    quicksort(arr, p_index + 1, ei,comp);
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
}

int main()
{
    // Execution time
    clock_t start, end;
    double execution_time;
    start = clock();

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
    quicksort(array, 0, n-1,&comparisons);
    printArrayToFile(output, array, n);
    printArrayWithComparisons(array, n,comparisons);

    end = clock();
    execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nExecution time : %lf\n",execution_time);

    return 0;
}