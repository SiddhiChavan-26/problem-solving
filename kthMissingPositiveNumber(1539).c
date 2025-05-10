#include <stdio.h>

int findKthPositive(int* arr, int arrSize, int k) {
    int missing = 0;
    int current = 1;
    int index = 0;

    while (missing < k) {
        if (index < arrSize && arr[index] == current) {
            index++;
        } else {
            missing++;
            if (missing == k) return current;
        }
        current++;
    }

    return -1; // Should not reach here
}

// Test
int main() {
    int arr[] = {2, 3, 4, 7, 11};
    int k = 5;
    int result = findKthPositive(arr, 5, k);
    printf("The %dth missing number is: %d\n", k, result); // Output: 9
    return 0;
}

