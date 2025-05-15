#include <stdio.h>

// Function to calculate h-index using binary search
int hIndex(int* citations, int citationsSize) {
    int left = 0, right = citationsSize - 1;
    int n = citationsSize;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (citations[mid] >= n - mid) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return n - left;
}

// Main function to test hIndex
int main() {
    // Example test case
    int citations[] = {0, 1, 3, 5, 6};  // Sorted array
    int citationsSize = sizeof(citations) / sizeof(citations[0]);

    int result = hIndex(citations, citationsSize);

    printf("The H-Index is: %d\n", result);  // Expected output: 3

    return 0;
}

