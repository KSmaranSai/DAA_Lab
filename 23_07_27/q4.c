#include <stdio.h>

void exchange_(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rotate_right(int * arr, int index){
    for (int i = index; i > 0; i--)
    {
        exchange_(arr+i,arr+i-1);
    }
}

void print(int * arr,int n){
    printf("\nElements : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",arr[i]);
    }
}

int main(){
    int n;
    int array[10] = {0,1,2,3,4,5,6,7,8,9};
    printf("Enter value of n : ");
    scanf("%d",&n);
    rotate_right(array,n);
    print(array,10);
return 0;
}