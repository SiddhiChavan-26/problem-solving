#include <stdio.h>
#include <stdlib.h>
int lengthOfLIS(int* nums, int numsSize) {
   if (numsSize == 0) {
        return 0;
    }
    
    int* dp = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1; 
    } 
    int maxLength = 1; 
    
    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > maxLength) {
            maxLength = dp[i]; 
        }
    }
    free(dp); 
    return maxLength;  
}
int main() {
    int nums1[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output: %d\n", lengthOfLIS(nums1, size1)); // Output: 4
    
    int nums2[] = {0, 1, 0, 3, 2, 3};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output: %d\n", lengthOfLIS(nums2, size2)); // Output: 4
    
    int nums3[] = {7, 7, 7, 7, 7, 7, 7};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Output: %d\n", lengthOfLIS(nums3, size3)); // Output: 1
    
    return 0;
}
