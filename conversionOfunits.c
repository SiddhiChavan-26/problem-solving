#include<stdio.h>
int main(){
	int ch;
	float x,y;
	printf("Enter the value : ");
	scanf("%d",&x);
	
	printf("Following are the choices for conversion of unit");
	printf("\n1.Convert sq.feet to sq.meter\n2.Convert sq.feet to guntha\n3.Convert sq.feet to acre\n4.Convert sq.feet to brass");
	printf("\n5.Convert sq.meter to sq.feet\n6.Convert sq.meter to guntha\n7.Convert sq.meter to acre\n8.Convert sq.meter to brass");
	printf("\n9.Guntha to sq.feet\n10.Guntha to sq.meter\n11.Guntha to acre");
	printf("\n12.Convert acre to sq.feet\n13.Convert acre to sq.meter\n14.Convert acre to guntha");
	printf("\n15.Convert brass to sq.feet\n16.Convert brass to sq.meter");
	
	switch(ch){
		case 1: printf("Conversion of sq.feet to sq.meter");
			y=x*0.092;
			printf("%f sq.feet = %f sq.meter",x,y);
			break;
			
		case 2: printf("Conversion of sq.feet to guntha");
			y=x*0.000918;
			printf("%f sq.feet = %f guntha",x,y);
			break;
		
		case 3: printf("Conversion of sq.feet to acre");
			y=x*0.00002295;
			printf("%f sq.feet = %f acre",x,y);
			break;
		
		case 4: printf("Conversion of sq.feet to brass");
			y=x*0.01;
			printf("%f sq.feet = %f brass",x,y);
			break;
		
		case 5: printf("Conversion of sq.meter to sq.feet");
			y=x*10.7639;
			printf("%f sq.meter = %f sq.feet",x,y);
			break;
		
		case 6: printf("Conversion of sq.meter to guntha");
			y=x*0.0098;
			printf("%f sq.meter = %f guntha",x,y);
			break;
		
		case 7: printf("Conversion of sq.meter to acre");
			y=x*0.0002471;
			printf("%f sq.meter = %f acre",x,y);
			break;
		
		case 8: printf("Conversion of sq.meter to brass");
			y=x*0.107;
			printf("%f sq.meter = %f brass",x,y);
			break;
		
		case 9: printf("Conversion of guntha to sq.feet");
			y=x*1089;
			printf("%f guntha = %f sq.feet",x,y);
			break;
		
		case 10: printf("Conversion of guntha to sq.meter");
			y=x*101.17;
			printf("%f guntha = %f sq.meter",x,y);
			break;
		
		case 11: printf("Conversion of guntha to acre");
			y=x*0.0247;
			printf("%f guntha = %f acre",x,y);
			break;
		
		case 12: printf("Conversion of acre to sq.feet");
			y=x*43560;
			printf("%f acre = %f sq.feet",x,y);
			break;
		
		case 13: printf("Conversion of acre to sq.meter");
			y=x*4056.85;
			printf("%f acre = %f sq.meter",x,y);
			break;
		
		case 14: printf("Conversion of acre to guntha");
			y=x*40;
			printf("%f acre = %f guntha",x,y);
			break;
		
		case 15: printf("Conversion of brass to sq.feet");
			y=x*100;
			printf("%f brass = %f sq.feet",x,y);
			break;
			
		case 16: printf("Conversion of brass to sq.meter");
			y=x*9.2903;
			printf("%f brass = %f sq.meter",x,y);
			break;
		default: printf("please enter a valid number");
	}
	return 0;
}
