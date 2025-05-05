#include <stdio.h>
#include <stdlib.h>

// Helper function to return the absolute difference
int absDiff(int a, int b) {
    return a > b ? a - b : b - a;
}

// Main function to find k closest elements
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
    int low = 0, high = arrSize - k;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (x - arr[mid] > arr[mid + k] - x)
            low = mid + 1;
        else
            high = mid;
    }

    // Prepare the result array
    int* result = (int*)malloc(sizeof(int) * k);
    for (int i = 0; i < k; ++i) {
        result[i] = arr[low + i];
    }

    *returnSize = k;
    return result;
}

// Example usage
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    int x = 3;
    int returnSize;

    int* result = findClosestElements(arr, arrSize, k, x, &returnSize);

    printf("Closest elements: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    free(result);
    return 0;
}