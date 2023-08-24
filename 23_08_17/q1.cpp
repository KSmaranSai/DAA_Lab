#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

void merge(int arr[], int low, int mid, int high, int *comparsions)
{
    int *arr1 = new int[high - low + 1];
    int i = low, j = mid + 1, k = 0;
    while ((i <= mid) && (j <= high))
    {
        (*comparsions)++;
        if (arr[i] > arr[j])
        {
            arr1[k++] = arr[j++];
        }
        else
        {
            arr1[k++] = arr[i++];
        }
    }
    while (i <= mid)
    {
        arr1[k++] = arr[i++];
    }
    while (j <= high)
    {
        arr1[k++] = arr[j++];
    }

    for (k = 0, i = low; k < (high - low + 1); k++, i++)
    {
        arr[i] = arr1[k];
    }
}

void mergeSort(int array[], int low, int high, int *comparisons)
{
    if (low >= high)
    {
        return;
    }
    int mid = low + ((high - low) / 2);
    mergeSort(array, low, mid, comparisons);
    mergeSort(array, mid + 1, high, comparisons);
    merge(array, low, mid, high, comparisons);
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
    mergeSort(array, 0, n, &comparisons);
    printArrayToFile(output, array, n);
    printArrayWithComparisons(array, n, comparisons);

    end = clock();
    execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nExecution time : %lf\n",execution_time);
    
    return 0;
}