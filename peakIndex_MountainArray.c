#include <stdio.h>

// Function to find the peak index in a mountain array
int peakIndexInMountainArray(int* arr, int arrSize) {
    int low = 1, high = arrSize - 2; // avoid boundary indices

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return mid;
        } else if (arr[mid] < arr[mid + 1]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // this should never be hit in a valid mountain array
}

// Main function to test the above logic
int main() {
    int arr[] = {1, 3, 5, 7, 6, 4, 2};  // Valid mountain array
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    int peakIndex = peakIndexInMountainArray(arr, arrSize);

    if (peakIndex != -1) {
        printf("Peak element is at index %d with value %d\n", peakIndex, arr[peakIndex]);
    } else {
        printf("No peak found (invalid mountain array)\n");
    }

    return 0;
}

