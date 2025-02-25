#include<stdio.h>
struct ticket {
    char name [50];
    int age;
};
int main(){
    struct ticket t1[50];
    int n,i=0,j=0;
    int sum = 0;
    
    printf("Enter the no. of family members : ");
    scanf("%d",&n);
    int age[n];
    printf("Enter information of each  members : ");
    for(i=0;i<n;i++){
        printf("Enter name of the member: ");
        scanf("%s",&t1[i].name);
        
        printf("Enter age of the member : ");
        scanf("%d",&t1[i].age);
        age[j] = t1[i].age;
        j++;
    }
    
    for(i=0;i<n;i++){
        if (age[j]<10 || age[j]>=50)
        sum += 0;
        if (age[j]>=10 && age[j]>25)
        sum += 20;
        if (age[j]>=25 && age[j]<50)
        sum += 50;
        
    }
    printf("The total price for %d family members is : %d",n,sum);
}
