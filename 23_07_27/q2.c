#include <stdio.h>
#include <stdlib.h>

void newArray(int *arr,int n){
	int *prefixArray = (int *)malloc(n*sizeof(int));
	int total=0;
	for(int i=0;i<n;i++){
		total = total + arr[i];
		prefixArray[i] = total;
	}
	printf("\nElements : \n");
	for(int i=0;i<n;i++){
		printf("%d\n",prefixArray[i]);
	}
}

int main(){
	int n;
	printf("Enter size : ");
	scanf("%d",&n);
	int *arr = (int *)malloc(n*sizeof(int));
	printf("\nElements after operation: \n");
	for(int i=0;i<n;i++){
		arr[i] = rand() % 10 + 1;
		printf("%d\n",arr[i]);
	}
	printf("\n");
	newArray(arr,n);	
	return 0;
}
