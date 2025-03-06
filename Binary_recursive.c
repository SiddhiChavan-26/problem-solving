#include<stdio.h>
int binarySearch( int list [],  int low , int  high , int  target){
	int mid ;
	while( low <= high){
		mid = (low + high )/2;
		if ( list[mid] == target){
			return (mid);
		}	
		if(list[mid] > target){
			return binarySearch(list , low , high-1 , target);
		}
		else{
			return binarySearch(list , low+1 , high, target);
		}
	}
	return (-1);
	
}
int main(){
	int N , i = 0 , target ,search , low , high ;
	printf("Enter the value of N : ");
	scanf("%d",&N);
	
	int list[N];
	printf("Enter %d elements : ",N);
	for ( i=0 ; i< N ; i++){
		scanf("%d" , &list[i]);
	}
	low = 0;
	high =  N -1;
	printf("Enter the data to search : ");
	scanf("%d" ,& target);
	
	search = binarySearch( list , low , high , target);
	
	if ( search >= 0) {
		printf("The data found at position: %d",search);
	}
	else{
		printf("Data not found.");
	}
}
