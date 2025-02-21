#include<stdio.h>
int main ()
{
 	 int rem,num,rev[10],n,j,i=0;
 printf("Enter the digits: ");
 	scanf("%d",&n);
 	
 	 printf("Enter the number: ");
 	 scanf("%d",&num);
 	 
 	 while(num>0){
 	 rem= num%10;
 
 	 rev[i] = rem;
 	 i++;
 	 num=num/10;
 	 }
 	 
 	 // display digits
 	 for(j=i-1;j>=0;j--){
 	 printf("%d\n",rev[j]);
 	 }
}


