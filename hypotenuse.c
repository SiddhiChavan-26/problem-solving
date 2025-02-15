#include<stdio.h>
#include<math.h>
double hypotenuse(double x,double y){
	double z = sqrt(x*x + y*y );
	return z;
}
int main(){
	double s1,s2;
	printf("Enter velues of two sides: ");
	scanf("%lf %lf",&s1,&s2);
	printf("Hypotenuse = %.2f\n",hypotenuse(s1,s2));
	return 0;
}
