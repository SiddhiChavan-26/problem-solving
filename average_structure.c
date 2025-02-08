#include<stdio.h>
struct student{
    int marks[4];
    char name[20];
};
int main(){
    struct student s[10];
    int i,n ,j,high=0,sum=0;
    float avg;
    
    for(i=0;i<n;i++){
        printf("\n\n Enter the student name :");
        scanf("%s",&s[i].name);
        printf("Enter marks of 4 subjects: ");
        for(i=0;i<n;i++){
            scanf("%d",&s[i].marks[j]);
            sum = sum + s[i].marks[j];
        }
        avg = sum/4;
        printf("The average marks is : %f",avg);
        }
        for(i=0;i<n;i++){
            high=0;
            for(j=0;j<4;j++){
                if(s[i].marks[j]>high)
                high = s[i].marks[j];
            }
            printf("\n");
            printf("The highest score of %s is : %d",s[i].name,high);
        }
}
