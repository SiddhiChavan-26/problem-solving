#include<stdio.h>
int  linearSearch( int list [] ,int  lpos , int  target)
{
	if (lpos < 0) {
        return -1;
    }

    if (list[lpos] == target) {
        return lpos;
    }
    
    return linearSearch(list, lpos - 1, target);
	
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
