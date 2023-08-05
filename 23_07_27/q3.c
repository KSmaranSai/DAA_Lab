#include <stdio.h>
#include <stdlib.h>

int findIndex(int *arr, int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    // Opening file
    FILE *intFile = fopen("IntArray.txt", "r");
    if (intFile == NULL)
    {
        printf("The file is not opened. The program will now exit.");
        exit(0);
    }
    else
    {
        printf("File Opened successfully.\n");
    }

    // Storing elements in file
    int num, n;
    int *array;
    printf("Enter number of integers to be taken : ");
    scanf("%d", &n);
    array = (int *)malloc(n * sizeof(int));
    printf("\nElements in array : \n");
    for (int i = 0; i < n && (num = getw(intFile)) != EOF; i++)
    {
        array[i] = num;
        printf("%d\n", array[i]);
    }

    // Operations on the array 1- Finding duplicates
    int *array2 = (int *)malloc(n * sizeof(int)); // will hold only values excluding duplicate
    int *no_of_instances = (int *)malloc(n * sizeof(int));

    int count_wd = 0;
    for (int i = 0; i < n; i++)
    {
        int index = findIndex(array2, count_wd, array[i]);
        if (index != -1)
        {
            no_of_instances[index]++;
        }
        else
        {
            array2[count_wd] = array[i];
            no_of_instances[count_wd] = 1;
            count_wd++;
        }
    }

    // Find number of duplicate elements and max instances of a number
    int duplicates = 0;
    int max_instances = 0;
    int max_index;
    for (int i = 0; i < count_wd; i++)
    {
        if (no_of_instances[i] > 1)
        {
            duplicates++;
        }

        if (max_instances < no_of_instances[i])
        {
            max_instances = no_of_instances[i];
            max_index = i;
        }
    }

    printf("\nArray without Duplicates : \n");
    for (int i = 0; i < count_wd; i++)
    {
        printf("%d\n",array2[i]);
    }
    
    printf("\nTotal number of duplicate values : %d\n", duplicates);
    printf("The most repeating element in the array : %d", array2[max_index]);
    return 0;
}