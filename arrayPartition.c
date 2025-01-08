#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int arrayPairSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int max = 0;
    for (int i = 0; i < numsSize; i += 2) {
        max = max + nums[i];
    }
    return max;
}

int main() {
    // Example input
    int nums[] = {1, 4, 3, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    // Call the function
    int result = arrayPairSum(nums, numsSize);

    // Print the result
    printf("The maximum sum of pairs is: %d\n", result);

    return 0;
}

