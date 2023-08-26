// Write a program for modified Insertion Sort using Binary Search. Find its Complexity.

#include <stdio.h>

int binarySearch(int *arr, int key, int j)
{
    int low = 0;
    int high = j;
    while (low <= high)
    {
        int mid = low + ((high - low) / 2);

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

void modifiedInsertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        int insertPos = binarySearch(arr, key, j);

        while (j >= insertPos)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    modifiedInsertionSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Time Complexity :
// O(n^2) as it has to swap n values every time even after getting the right index to insert from Binary Search
