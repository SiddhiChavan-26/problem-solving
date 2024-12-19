#include<stdio.h>
int main(){
	int n,i,found=0;
	printf("Enter value of n: ");
	scanf("%d",&n);
	
	int arr[n];
	printf("\nEnter %d elements: ",n);
	for(i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	
	for(i=0; i<n; i++){
		if(i == 0){
			arr[i] = arr[i];
		}
		else{
			arr[i] = arr[i] + arr[i-1];
		}
	}
	
	for(i=0; i<n; i++){
		if(i == 0){
			if(arr[i] == arr[n-1]-arr[i]){
				found++;
				printf("Pivot index is: %d",i);
				break;
			}
		}
		else{
			if(arr[i-1] == arr[n-1] - arr[i]){
				found++;
				printf("Pivot index is: %d",i);
				break;
			}
			
		}
	}
	
	if(found==0){
		printf("There is no index that satisfies the condition!!");
	}
}

