#include<stdio.h>
int main(){
    int fam[50];
    int total;
    int i,n;
    
    printf("Enter the no. of family members: ");
    scanf("%d",&n);
    printf("Enter the age of each family member : ");
    for(i=0;i<n;i++){
        scanf("%d",&fam[i]);
    }
    total = 0;
    for(i=0;i<n;i++){
        if(fam[i]>=55)
        total = total+100;
        else if (fam[i]>=21 && fam[i]<= 54)
        total = total + 155;
        else if (fam[i]>=13 && fam[i]<= 20)
        total = total + 100;
        else if (fam[i]>=3 && fam[i]<= 12)
        total = total + 75;
        else total = total + 0;
    }
    printf("The total charges of ticket is %d ",total);
}
