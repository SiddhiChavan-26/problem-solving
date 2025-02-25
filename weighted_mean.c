#include<stdio.h>
int main(){
    int n,i;
    printf("Enter the no.of elements: ");
    scanf("%d",&n);
    int X[n] , W[n];
    
    printf("Enter the elements of array x: \n");
    for(i=0;i<n;i++){
        scanf("%d",&X[i]);
    }
    
    printf("Enter the elements of array W: \n");
    for(i=0;i<n;i++){
        scanf("%d",&W[i]);
    }
    double weighted_sum = 0;
    int total_weight = 0;
    for ( i=0;i<n;i++){
        weighted_sum += X[i] * W[i];
        total_weight += W[i];
          
    }
    double weighted_mean = weighted_sum/total_weight;
    printf("Weighted mean : %.1f\n",weighted_mean);
    return 0;
}
