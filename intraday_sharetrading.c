#include<stdio.h>
int main(){
	int quantity;
	float buy_price, sell_price , total_cost, total_sales, brokerage_buy, brokerage_sales,service_tax, STT,stamp_duty,regulatory_charges,total_charges,profit;
	
	printf("Enter quantity: ");
	scanf("%d",&quantity);
	printf("Enter buy price: ");
	scanf("%f",&buy_price);
	printf("Enter sell price: ");
	scanf("%f",&sell_price);
	
	total_cost = buy_price* quantity;
	total_sales = sell_price*quantity;
	
	brokerage_buy = total_cost * 0.03/100;
	brokerage_sales = total_sales * 0.03/100;
	service_tax = (brokerage_buy + brokerage_sales)*10.36/100;
	STT = total_sales * 0.025/100;
	stamp_duty = (total_cost + total_sales)*0.002/100;
	regulatory_charges = (total_cost + total_sales)* 0.004/100;
	total_charges = brokerage_buy + brokerage_sales + service_tax + STT + stamp_duty + regulatory_charges;
	profit = total_sales - total_cost - total_charges;
	
	printf("The profit is: %f",profit);
	return 0; 
}
