#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    int* env1 = *(int**)a;
    int* env2 = *(int**)b;

    if (env1[0] == env2[0]) {
        return env2[1] - env1[1]; // Descending height if same width
    }
    return env1[0] - env2[0]; // Ascending width
}

// Binary search helper for LIS
int binarySearch(int* dp, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = (left + right) / 2;
        if (dp[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
    if (envelopesSize == 0) return 0;

    // Sort the envelopes
    qsort(envelopes, envelopesSize, sizeof(int*), compare);

    // Extract heights
    int* dp = (int*)malloc(sizeof(int) * envelopesSize);
    int length = 0;

    for (int i = 0; i < envelopesSize; ++i) {
        int height = envelopes[i][1];
        int idx = binarySearch(dp, length, height);
        dp[idx] = height;
        if (idx == length) length++;
    }

    free(dp);
    return length;
}
int main() {
    int data[][2] = {{5,4}, {6,4}, {6,7}, {2,3}};
    int size = sizeof(data)/sizeof(data[0]);

    // Convert to int** format
    int** envelopes = malloc(size * sizeof(int*));
    int* colSizes = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        envelopes[i] = malloc(2 * sizeof(int));
        envelopes[i][0] = data[i][0];
        envelopes[i][1] = data[i][1];
        colSizes[i] = 2;
    }

    int result = maxEnvelopes(envelopes, size, colSizes);
    printf("Max envelopes: %d\n", result);

    // Free memory
    for (int i = 0; i < size; ++i)
        free(envelopes[i]);
    free(envelopes);
    free(colSizes);

    return 0;
}

