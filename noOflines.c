#include<stdio.h>
int main(){
	double length,width;
	double top,bottom,left,right;
	double pointsize;
	int double_spaced;
	
	printf("Enter the length and width of the paper(in inches) : ");
	scanf("%lf %lf",&length ,&width);
	
	printf("Enter top , bottom , left, right margin (in inches): ");
	scanf("%lf %lf %lf %lf",&top, &bottom, &left,&right);
	printf("Enter the point size of the text : ");
	scanf("%lf",&pointsize);
	printf("Enter 1 if double spaced , 0 otherwise:");
	scanf("%d",&double_spaced);
	
	double printable_width = width-(left+right);
	double printable_height = length - (top+bottom);
	double pointsize_in_inches = pointsize /72.0;
	int char_per_line = (int)(printable_width / pointsize_in_inches);
	
	double line_height;
	if(double_spaced){
		line_height = 2*pointsize_in_inches;
		
	}
	else{
	 line_height = pointsize_in_inches;	
	}
	
	int noOf_lines= (int)(printable_height/line_height);
	printf("No. of characters per line : %d\n",char_per_line);
	printf("No. of lines per page : %d\n",noOf_lines);
	return 0;
}
