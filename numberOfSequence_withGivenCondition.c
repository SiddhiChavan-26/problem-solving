#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Comparison function for qsort (ascending order)
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Function to compute (2^n) % MOD using fast exponentiation
int power(int base, int exp) {
    long long result = 1;
    long long b = base;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * b) % MOD;
        b = (b * b) % MOD;
        exp /= 2;
    }
    return (int)result;
}

// Main function
int numSubseq(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);  // Sort the array

    int left = 0, right = numsSize - 1;
    int count = 0;

    while (left <= right) {
        if (nums[left] + nums[right] <= target) {
            int exp = right - left;
            count = (count + power(2, exp)) % MOD;
            left++;
        } else {
            right--;
        }
    }

    return count;
}

// Test driver
int main() {
    int nums[] = {3, 5, 6, 7};
    int target = 9;
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = numSubseq(nums, size, target);
    printf("Number of valid subsequences: %d\n", result);

    return 0;
}

