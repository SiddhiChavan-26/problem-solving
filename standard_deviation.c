#include<stdio.h>
#include<math.h>
float calculate (int num[] ,int n){
	int sum=0,i=0;
	float avg;
	for(i=0;i<n;i++){
		sum = sum + num[i];
	}
	avg = sum/n;
	return avg;
}
int main(){
	int N,i=0;
	float variance,standard_deviation,average;
	
	printf("Enter the value of N : ");
	scanf("%d",&N);
	int num[N],u[N];
	
	printf("Enter %d numbers: ",N);
	for(i=0;i<N;i++){
		scanf("%d",&num[i]);
	}
	average = calculate(num,N);
	
	for(i=0;i<N;i++)
	{
		u[i] = (num[i]-average)*(num[i]-average);
		
	}
	variance = calculate(u,N);
	standard_deviation = sqrt(variance);
	printf("The standard deviation is : %f",standard_deviation);
	return 0;
	
}
