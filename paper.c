#include<stdio.h>
int main(){
    int num,rem,quo;
    float amount =0;
    printf("Enter the no.of pages : ");
    scanf("%d",&num);
    
    quo = num/1000;
    amount = amount + quo*1000*0.03;
    rem = num%1000;
    
    quo = num/500;
    amount = amount + quo*500*0.04;
    rem = num%500;
    
    quo = num/100;
    amount = amount + quo*100*0.055;
    rem = num%100;
    
    amount = amount + rem*0.10;
    printf("The total amount is : %f",amount);
    return 0;
}
