#include <stdio.h>

int findMin(int* nums, int numsSize) {
    int low = 0, high = numsSize - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return nums[low];
}

int main() {
    // Example rotated sorted array (no duplicates)
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int size = sizeof(nums) / sizeof(nums[0]);

    int minValue = findMin(nums, size);

    printf("The minimum value in the rotated sorted array is: %d\n", minValue);

    return 0;
}

