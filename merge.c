#include<stdio.h>
#include<math.h>
void merge(int arr[],int low,int mid,int high)
{
	int n1,n2,i,j,k;
	n1 = mid - low +1;
	n2 = high -mid;
	int l[n1+1];
	int r[n2+1];
	for( i=1;i<n1;i++)
	{
		l[i] = arr[low + i - 1];
	}
	for( j;j<n2;j++)
	{
	}
	l[n1 +1]=INFINITY;
	r[n2 +1]=INFINITY;
	i=1;
	j=1;
	for( k=low;k<high;k++)
	{
		if(l[i]<=r[j])
		{
			arr[k ] = l[j];
			i++;
		}
		else
		{
			arr[k]= r[j];
			j++;
		}
	}
}
void merge_sort(int arr[],int low,int high)
{	int mid;
	if(low<high)
	{	mid = (low+high)/2;
		merge_sort(arr,low,mid);
		merge_sort(arr,mid+1,high);
		
		merge(arr,low,mid,high);
	}
}
int main()
{
	int size,i;
	printf("enter size");
	scanf("%d",&size);
	int arr[size];
	printf("enter elements:\n");
	for(i = 0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	int n = sizeof(arr) / sizeof(arr[0]);
	merge_sort( arr, 0, n - 1);
	for(i = 0;i<size;i++)
	{
		printf("%d",arr[i]);
	}
	 return 0;
}
