#include <stdio.h>
int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j])
            return nums1[i];
        else if (nums1[i] < nums2[j])
            i++;
        else
            j++;
    }
    return -1;
}

int main() {
    int nums1[] = {1, 2, 3, 4, 5};  
    int nums2[] = {3, 4, 5, 6, 7};  
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    int commonElement = getCommon(nums1, nums1Size, nums2, nums2Size);

    if (commonElement != -1) {
        printf("The first common element is: %d\n", commonElement);
    } else {
        printf("No common elements found.\n");
    }

    return 0;
}

