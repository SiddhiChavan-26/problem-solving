#include <stdio.h>

double findMedianSortedArrays(int* nums1, int m, int* nums2, int n) {
    int merged[m + n];
    int i = 0, j = 0, k = 0;

    // Merge both arrays
    while (i < m && j < n) {
        if (nums1[i] < nums2[j])
            merged[k++] = nums1[i++];
        else
            merged[k++] = nums2[j++];
    }

    while (i < m) {
        merged[k++] = nums1[i++];
    }

    while (j < n) {
        merged[k++] = nums2[j++];
    }

    // Find median
    int total = m + n;
    if (total % 2 == 0) {
        return (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
    } else {
        return merged[total / 2];
    }
}
int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};

    int m = sizeof(nums1) / sizeof(nums1[0]);
    int n = sizeof(nums2) / sizeof(nums2[0]);

    double median = findMedianSortedArrays(nums1, m, nums2, n);
    printf("Median: %.1f\n", median);

    return 0;
}

