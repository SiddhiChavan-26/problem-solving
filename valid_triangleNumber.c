#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int triangleNumber(int* nums, int numsSize) {
    int count = 0;
    qsort(nums, numsSize, sizeof(int), compare);  // Sort the array

    for (int k = numsSize - 1; k >= 2; k--) {
        int i = 0, j = k - 1;
        while (i < j) {
            if (nums[i] + nums[j] > nums[k]) {
                count += (j - i);  // All elements between i and j form valid triangles with k
                j--;
            } else {
                i++;
            }
        }
    }
    return count;
}

// Example usage
int main() {
    int nums[] = {2, 2, 3, 4};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = triangleNumber(nums, size);
    printf("Number of valid triangles: %d\n", result);
    return 0;
}

