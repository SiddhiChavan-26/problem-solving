#include<stdio.h>
int maximumCount(int* nums, int numsSize) {
   int left = 0, right = numsSize - 1;
    int pos = 0, neg = 0;
    while (left <= right) {
        int mid = (left+right)/2;
        if (nums[mid] > 0) {
            right = mid - 1; 
        } else {
            left = mid + 1;  
        }
    }
    pos = numsSize - left;

    //for negative
    left = 0;
    right = numsSize - 1;
    while (left <= right) {
        int mid = (left+right) / 2;
        if (nums[mid] < 0) {
            left = mid + 1;  
        } else {
            right = mid - 1;
        }
    }
    neg = left;

    if(pos > neg)
        return pos;
    else
        return neg;
}
int main() {
    int nums[] = {-3, -2, -1, 0, 0, 1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = maximumCount(nums, numsSize);
    printf("Maximum count of positive or negative numbers: %d\n", result);

    return 0;
}
