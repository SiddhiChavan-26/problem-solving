#include<stdio.h>
int  linearSearch( int list [] ,int  lpos , int  target)
{
	int i=0;
	for(i = 0; i <= lpos ; i++){
	if( list[i] == target){
		return i;
	}
	}
	return (-1);
	
}
int main()
{
	int i = 0 , target ,N ,search ,last_position;
	printf("Enter the value of N: ");
	scanf("%d",&N);
	
	last_position = N -1;
	int arr[N];
	printf("Enter %d elements : ",N);
	for( i= 0 ; i < N ; i ++){
	scanf("%d",&arr[i]);
	}
	
	printf("Enter the data to search: ");
	scanf("%d" , &target);
	
	search = linearSearch(arr , last_position ,target);
	
	if(search >= 0){
		printf("The data found at position : %d",search);
	}
	else{
		printf("The data not found.");
	}
	 
}
