#include<stdio.h>
int main(){
	int arr[5];
	int i,j,temp;
	printf("Enter 5 numbers: ");
	for(i=0;i<5;i++){
		scanf("%d",&arr[i]);
	}
	printf("Array before reversing :\n");
	for(i=0;i<5;i++){
		printf("Arr[%d]=%d\n",i,arr[i]);
	}
	for (i=0,j=4;i<j;i++,j--){
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
	printf("\nArray after reversing:\n");
	for(i=0;i<5;i++){
		printf("Arr[%d]=%d\n",i,arr[i]);
	}
	return 0;
}
