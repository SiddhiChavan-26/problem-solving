#include <stdio.h>
#include <limits.h>


void find_min_max_avg(int *marks, int n, int *min, int *max, float *avg);

#define MAX_STUDENTS 100

int main() {
    int N,i;
    printf("Enter the number of students (up to %d): ", MAX_STUDENTS);
    scanf("%d", &N);

    
    if (N > MAX_STUDENTS) {
        printf("The number of students exceeds the maximum allowed (%d).\n", MAX_STUDENTS);
        return 1;
    }

    
    int marks[MAX_STUDENTS];


    printf("Enter the marks of %d students:\n", N);
    for (i = 0; i < N; i++) {
        printf("Student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    int min, max;
    float avg;
    find_min_max_avg(marks, N, &min, &max, &avg);

    // Output the results
    printf("Minimum marks: %d\n", min);
    printf("Maximum marks: %d\n", max);
    printf("Average marks: %.2f\n", avg);

    return 0;
}


void find_min_max_avg(int *marks, int n, int *min, int *max, float *avg) {
    *min = 100;
    *max = 0;
    int sum = 0,i;

    for (i = 0; i < n; i++) {
        if (marks[i] < *min) {
            *min = marks[i];
        }
        if (marks[i] > *max) {
            *max = marks[i];
        }
        sum += marks[i];
    }

    *avg = (float)sum / n;
}
