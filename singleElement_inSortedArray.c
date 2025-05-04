#include <stdio.h>

int singleNonDuplicate(int* nums, int numsSize) {
    int low = 0, high = numsSize - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        // Make sure mid is even
        if (mid % 2 == 1) {
            mid--;
        }

        if (nums[mid] == nums[mid + 1]) {
            low = mid + 2;
        } else {
            high = mid;
        }
    }

    return nums[low];
}


int main() {
    int nums[] = {1, 1, 2, 3, 3, 4, 4, 8, 8}; // Example input
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = singleNonDuplicate(nums, numsSize);
    printf("The single non-duplicate element is: %d\n", result);
    return 0;
}
