#include <stdio.h>
void rotate(int* nums, int numsSize, int k) {
     if (numsSize <= 1 || k <= 0) return; 
    k = k % numsSize;  

    
    void reverse(int* arr, int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    reverse(nums, 0, numsSize - 1);

    reverse(nums, 0, k - 1);

    reverse(nums, k, numsSize - 1);
}
int main() {
   
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3; 

    printf("Original array: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    rotate(nums, numsSize, k);

    printf("Rotated array: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}

