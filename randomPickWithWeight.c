#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int* prefixSum;
    int size;
    int totalSum;
} Solution;

// Constructor
Solution* solutionCreate(int* w, int wSize) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    obj->prefixSum = (int*)malloc(sizeof(int) * wSize);
    obj->size = wSize;

    obj->prefixSum[0] = w[0];
    for (int i = 1; i < wSize; i++) {
        obj->prefixSum[i] = obj->prefixSum[i - 1] + w[i];
    }

    obj->totalSum = obj->prefixSum[wSize - 1];
    return obj;
}

// Function to pick index based on weight
int solutionPickIndex(Solution* obj) {
    int target = rand() % obj->totalSum + 1;

    int left = 0, right = obj->size - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (target > obj->prefixSum[mid])
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

// Destructor
void solutionFree(Solution* obj) {
    free(obj->prefixSum);
    free(obj);
}

// Main function for local testing
int main() {
    srand(time(NULL)); // Seed the random number generator

    // Example weights array
    int weights[] = {1, 3, 2};
    int size = sizeof(weights) / sizeof(weights[0]);

    // Create solution object
    Solution* obj = solutionCreate(weights, size);

    // Call pickIndex multiple times to observe distribution
    printf("Picked indices: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", solutionPickIndex(obj));
    }
    printf("\n");

    // Clean up memory
    solutionFree(obj);

    return 0;
}

