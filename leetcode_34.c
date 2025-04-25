#include <stdio.h>
#include <stdlib.h>

// Function to find the first occurrence of target
int findFirst(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1, first = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            first = mid;
            right = mid - 1; // move left
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return first;
}

// Function to find the last occurrence of target
int findLast(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1, last = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            last = mid;
            left = mid + 1; // move right
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return last;
}

// Function to return the first and last positions as an array
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = findFirst(nums, numsSize, target);
    result[1] = findLast(nums, numsSize, target);
    *returnSize = 2;
    return result;
}

// Main function to test the code
int main() {
    int nums[] = {5, 7, 7, 8, 8, 10};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 8;
    int returnSize;

    int* result = searchRange(nums, numsSize, target, &returnSize);

    printf("First and last position of %d: [%d, %d]\n", target, result[0], result[1]);

    // Free dynamically allocated memory
    free(result);

    return 0;
}