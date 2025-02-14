#include<stdio.h>
#define MAX_STUDENT 100
int main(){
	int n ,marks[MAX_STUDENT];
	int i,sum =0,count =0;
	int high=-1,low=101;
	int frequency[101];
	int mode=-1,max_frequency=0;
	
	
	printf("Enter the no. of students: ");
	scanf("%d",&n);
	printf("Enter marks of each student(-1 for absent student) : ");
	for(i=0;i<n;i++){
		printf("Student %d: ",i+1);
		scanf("%d",&marks[i]);
		
		if(marks[i]!= -1){
			sum += marks[i];
			count ++;
		if(marks[i]>high)
	    	high = marks[i];
		if(marks[i]<low)
			low = marks[i];
		
		int frequency[marks[i]];
		
		}
	}
	
	double average = (double) sum/count ;
	for(i=0;i<100;i++){
		if(frequency[i]>max_frequency){
			max_frequency = frequency[i];
			mode = i;
		}
	}
	
	printf("Average score of class is : %.2f\n",average);
	printf("Highest score : %d\n",high);
	printf("Lowest score : %d\n",low);
	printf("Most common marks: %d\n",mode);
	printf("list of absent students: ");
	for(i=0;i<n;i++){
		if(marks[i]==-1){
			printf("Student %d",i+1);
		}
	}
	printf("No student were absent.");
	return 0;

}
