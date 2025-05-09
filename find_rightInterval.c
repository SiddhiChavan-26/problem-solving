#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int index;
} IntervalStart;

// Comparator for qsort: sort by start time
int compare(const void* a, const void* b) {
    return ((IntervalStart*)a)->start - ((IntervalStart*)b)->start;
}

// Binary search for the smallest start >= target
int binarySearch(IntervalStart* sorted, int size, int target) {
    int left = 0, right = size - 1;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sorted[mid].start >= target) {
            result = sorted[mid].index;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int* findRightInterval(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize) {
    *returnSize = intervalsSize;
    int* result = (int*)malloc(sizeof(int) * intervalsSize);

    // Step 1: Create array of IntervalStart to sort by start
    IntervalStart* sorted = (IntervalStart*)malloc(sizeof(IntervalStart) * intervalsSize);
    for (int i = 0; i < intervalsSize; i++) {
        sorted[i].start = intervals[i][0];
        sorted[i].index = i;
    }

    // Step 2: Sort intervals by start time
    qsort(sorted, intervalsSize, sizeof(IntervalStart), compare);

    // Step 3: For each interval, find right interval using binary search
    for (int i = 0; i < intervalsSize; i++) {
        int end = intervals[i][1];
        result[i] = binarySearch(sorted, intervalsSize, end);
    }

    // Clean up
    free(sorted);
    return result;
}
#include <stdio.h>
#include <stdlib.h>

// Include the same function definitions here or assume they are declared before main

int main() {
    // Example intervals: {{1,2}, {2,3}, {3,4}}
    int intervalsData[3][2] = {
        {1, 2},
        {2, 3},
        {3, 4}
    };
    
    int intervalsSize = 3;
    int* intervals[3];
    int intervalsColSize[3] = {2, 2, 2};

    // Point to each row in intervalsData
    for (int i = 0; i < intervalsSize; i++) {
        intervals[i] = intervalsData[i];
    }

    // Call the function
    int returnSize;
    int* result = findRightInterval(intervals, intervalsSize, intervalsColSize, &returnSize);

    // Print result
    printf("Output: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free allocated memory
    free(result);
    
    return 0;
}

