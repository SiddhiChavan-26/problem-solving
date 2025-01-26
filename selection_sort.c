#include<stdio.h>
int main(){
	int i,j,n,a[100],min,temp;
	
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter %d elements: ",n);
	for (i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<(n-1);i++){
		min =i;
		for(j=i+1;j<n;j++){
			if(a[min]> a[j])
			min=j;
		}
		if(min != i)
		{
			temp = a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
	printf("elements after sorting: \n");
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
}
