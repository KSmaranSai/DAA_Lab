#include <stdio.h>
#include <stdlib.h>

void newArray(int *arr,int n){
	int totalProduct = 1;
	for(int i=0;i<n;i++){
		totalProduct = totalProduct*arr[i];
	}
	
	printf("\nElements : ");
	for(int i=0;i<n;i++){
		arr[i] = totalProduct/arr[i];
		printf("\t%d",arr[i]);
	}
	printf("\n");
}

int main(){
	int n;
	printf("Enter size : ");
	scanf("%d",&n);
	int *arr = (int *)malloc(n*sizeof(int));
	printf("\nElements : ");
	for(int i=0;i<n;i++){
		arr[i] = rand() % 10 + 1;
		printf("\t%d",arr[i]);
	}
	newArray(arr,n);	
	return 0;
}
