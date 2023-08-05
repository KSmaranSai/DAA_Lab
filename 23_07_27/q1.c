#include <stdio.h>
#include <stdlib.h>

void find(int *arr,int n){
	if (n<2){
		printf("Cannot find!!\n");
		return;
	}
	int max1 = -999998, max2 = -999999;
	int min1 = 999999, min2 = 999998;
	for(int i =0;i<n;i++){
	
		if(max1<arr[i]){
			max2 = max1;
			max1 = arr[i];
		}
		else if(max2<arr[i]){
			max2 = arr[i];
		}
		
		
		if(min1>arr[i]){
			min2 = min1;
			min1 = arr[i];
		}
		else if(min2>arr[i]){
			min2 = arr[i];
		}
	
	}

	printf("\nSecond Largest : %d\n",max2);
	printf("Second Smallest : %d\n",min2);
}

int main(){

	int n;
	printf("Enter size : ");
	scanf("%d",&n);
	int *arr = (int *)malloc(n*sizeof(int));
	printf("Elements : \n");
	for(int i=0;i<n;i++){
		arr[i] = rand() % 50;
		printf("%d\n",arr[i]);
	}
	find(arr,n);	
	return 0;
}
