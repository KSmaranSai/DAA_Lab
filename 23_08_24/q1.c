// The idea of Standard  Merge Sort is to divide the data-set into smaller data-sets, sort those
// smaller data-sets and then join them (merge them) together. Write a program for modified Mergesort,
// where divide the data-set into smaller data-sets of size less than or equal to k, sort those smaller
// data-sets (<= k) using Bubble Sort and then join them (merge them) together.
// Find the complexity of the Modified Merge Sort

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void merge(int arr[], int low, int mid, int high)
{
    int *arr1 = (int *)malloc(sizeof(int) * (high - low + 1));
    int i = low, j = mid + 1, k = 0;
    while ((i <= mid) && (j <= high))
    {
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

void mergeSort(int array[], int low, int high, int k)
{
    if (low < high)
    {
        if ((high - low + 1) <= k)
        {
            bubbleSort(array + low, high - low + 1);
        }
        else
        {
            int mid = low + ((high - low) / 2);
            mergeSort(array, low, mid, k);
            mergeSort(array, mid + 1, high, k);
            merge(array, low, mid, high);
        }
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // Size threshold for using Bubble Sort

    mergeSort(arr, 0, n - 1, k);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Time Complexity:
// If value of k is small then the complexity is close to O(nlogn) and as k increases time complexity approaches O(n^2)