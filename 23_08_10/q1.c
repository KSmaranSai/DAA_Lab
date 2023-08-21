// Write a program to implement Binary Search to give the position of
// leftmost appearance of the element in the array being searched. Display the number of
// comparisons made while searching

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *array, int size, int key,int *comparisions)
{
    int index = -1;
    int high = size, low = 0;

    while (low <= high)
    {
        (*comparisions)++;
        int mid = low + ((high - low) / 2);
        if (array[mid] == key)
        {
            index = mid;
            high = mid-1;
        }
        else if (array[mid] < key)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }

    return index;
}

int main()
{
    // initalising array
    int *array;
    int n =5, key,comparsions = 0;
    printf("Enter size of array : ");
    scanf("%d", &n);
    array = (int *)malloc(sizeof(int) * n);

    // taking inputs for the array
    printf("Enter elements of array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Enter Key : ");
    scanf("%d", &key);


    int index = binarySearch(array, n, key,&comparsions);
    printf("%d found at : %d\n",key,index);
    printf("Number of comparisions : %d",comparsions);

    return 0;
}