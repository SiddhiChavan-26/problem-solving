#include<stdio.h>
#include<math.h>
int main(){
	double P,r,EMI,Interest,Principal,Balance;
	int n,month;
	
	printf("Enter the loan amount: ");
	scanf("%lf",&P);
	printf("Enter the annual interest rate(in percent): ");
	scanf("%lf",&r);
	printf("Enter the repayment period(inmonth): ");
	scanf("%d",&n);
	
	double r_monthly = r/12/100;
	EMI = P*r_monthly*pow(1+r_monthly,n)/(pow(1+r_monthly,n)-1);
	Balance = P;
	
	printf("\nMonth\tEMI\t\tInterest\tPrincipal\tBalance\n");
	for(month=1;month<=n && Balance>0;month++){
		Interest = Balance *r_monthly;
		Principal = EMI - Interest;
		Balance -= Principal;
		
		if (Balance<0){
			Balance =0;
		}
		printf("%d\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",month,EMI,Interest,Principal,Balance);
		
	} 
	return 0;
}
