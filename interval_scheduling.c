#include <stdio.h>
#include <stdlib.h>

// Structure to store interval information
typedef struct {
    int start, end;
} Interval;

// Comparator function for sorting intervals by end time
int compare(const void *a, const void *b) {
    return ((Interval*)a)->end - ((Interval*)b)->end;
}

// Function to find the maximum number of non-overlapping intervals
void intervalScheduling(Interval intervals[], int n) {
    // Step 1: Sort intervals by end time
    qsort(intervals, n, sizeof(Interval), compare);
    
    printf("Selected intervals: ");
    
    // Step 2: Select the first interval
    int count = 1;
    int lastEnd = intervals[0].end;
    printf("[%d, %d] ", intervals[0].start, intervals[0].end);
    
    // Step 3: Iterate through intervals
    for (int i = 1; i < n; i++) {
        if (intervals[i].start >= lastEnd) {
            printf("[%d, %d] ", intervals[i].start, intervals[i].end);
            lastEnd = intervals[i].end;
            count++;
        }
    }
    
    printf("\nMaximum number of non-overlapping intervals: %d\n", count);
}

int main() {
    int n;
    printf("Enter the number of intervals: ");
    scanf("%d", &n);
    
    Interval intervals[n];
    printf("Enter the start and end times of the intervals:\n");
    for (int i = 0; i < n; i++) {
        printf("Interval %d - Start: ", i + 1);
        scanf("%d", &intervals[i].start);
        printf("Interval %d - End: ", i + 1);
        scanf("%d", &intervals[i].end);
    }
    
    // Call the function to compute and print the result
    intervalScheduling(intervals, n);
    
    return 0;
}

