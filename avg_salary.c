#include <stdio.h>
#include <limits.h>

double average(int* salary, int salarySize) {
    int min = INT_MAX;
    int max = INT_MIN;
    int sum=0;
    
    for(int i=0; i<salarySize; i++){
        sum=sum+salary[i];
        if(salary[i]>max)
            max=salary[i];
        if(salary[i]<min)
            min=salary[i];
    }
    sum=sum-min;
    sum=sum-max;

    return (double)sum / (salarySize - 2);
}

int main() {
    // Test input
    int salary[] = {48000, 59000, 99000, 13000, 78000, 45000, 31000, 17000, 39000, 37000, 
                    93000, 77000, 33000, 28000, 4000, 54000, 67000, 6000, 1000, 11000};
    int salarySize = sizeof(salary) / sizeof(salary[0]);

    // Call the function
    double result = average(salary, salarySize);

    // Print the result
    printf("The average salary excluding the minimum and maximum is: %.5f\n", result);

    return 0;
}


