#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Binary search to find first index in potions such that spell * potion >= success
int binarySearch(int *potions, int potionsSize, long long spell, long long success) {
    int left = 0, right = potionsSize - 1, ans = potionsSize;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if ((long long)potions[mid] * spell >= success) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return potionsSize - ans;
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize){
    qsort(potions, potionsSize, sizeof(int), compare);

    int* result = (int*)malloc(sizeof(int) * spellsSize);
    *returnSize = spellsSize;

    for (int i = 0; i < spellsSize; i++) {
        result[i] = binarySearch(potions, potionsSize, spells[i], success);
    }

    return result;
}

// Example usage
int main() {
    int spells[] = {10, 20, 30};
    int potions[] = {1, 2, 3, 4, 5};
    int success = 100;
    int returnSize;

    int *result = successfulPairs(spells, 3, potions, 5, success, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}

