/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;

    int* leftSum = (int*)malloc(n * sizeof(int));
    int* rightSum = (int*)malloc(n * sizeof(int));
    int* answer = (int*)malloc(n * sizeof(int));

    for(int i=0; i < n; i++){
        if(i== 0)
            leftSum[i] = 0;
        else{
            leftSum[i] = leftSum[i-1] + nums[i-1];
        }
    }
    
    for(int i=n-1; i >= 0; i--){
        if(i== n-1)
            rightSum[i] = 0;
        else{
            rightSum[i] = rightSum[i+1] + nums[i+1];
        }
    }

    for(int i=0; i<n ; i++){
        answer[i] = abs(leftSum[i] - rightSum[i]);
    }

    *returnSize = n;
    return answer;

}

int main() {
    int nums[] = {10, 4, 8, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = leftRightDifference(nums, numsSize, &returnSize);

    // Print the result
    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    // Free the allocated memory
    free(result);

    return 0;
}

