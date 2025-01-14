#include <stdio.h>
#include <stdlib.h>
int specialArray(int* nums, int numsSize) {
    for (int x = 0; x <= numsSize; x++) {
        int count = 0;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] >= x) {
                count++;
            }
        }
        if (count == x) {
            return x;
        }
    }
    return -1;
}
int main() {
    // Test Case 1
    int nums1[] = {3, 5};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Special Array for nums1: %d\n", specialArray(nums1, size1)); 

    // Test Case 2
    int nums2[] = {0, 0};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Special Array for nums2: %d\n", specialArray(nums2, size2)); 

    // Test Case 3
    int nums3[] = {0, 4, 3, 0, 4};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Special Array for nums3: %d\n", specialArray(nums3, size3)); 

    // Test Case 4
    int nums4[] = {10, 5, 0, 1};
    int size4 = sizeof(nums4) / sizeof(nums4[0]);
    printf("Special Array for nums4: %d\n", specialArray(nums4, size4));

    return 0;
}
