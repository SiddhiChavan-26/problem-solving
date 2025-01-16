#include <stdio.h>
#include <stdlib.h>

// Comparison function for sorting in ascending order
int compare(const void *a, const void *b) {
    int int_a = *(int*)a;
    int int_b = *(int*)b;

    if (int_a > int_b) return 1;
    if (int_a < int_b) return -1;
    return 0;
}

int thirdMax(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare); // Sort the array in ascending order

    int count = 1;
    for (int i = numsSize - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            count++;
        }
        if (count == 3) {
            return nums[i]; // Return the third maximum element
        }
    }
    return nums[numsSize - 1]; // Return the maximum if there is no third maximum
}

int main() {
    int nums[] = {3, 2, 1, -2147483648};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = thirdMax(nums, numsSize);
    printf("The third maximum number is: %d\n", result);

    return 0;
}

