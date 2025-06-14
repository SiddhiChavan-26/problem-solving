#include <stdio.h>
#include <stdlib.h>

int* stableMountains(int* height, int heightSize, int threshold, int* returnSize){
    int *res = malloc(sizeof(int) * heightSize);
    int count = 0;
    for(int i = 1; i < heightSize; i++){
        if(height[i - 1] > threshold){
            res[count++] = i;
        }
    }
    *returnSize = count;
    return res;
}
int main() {
    int height[] = {1, 2, 3, 4, 5};
    int threshold = 2;
    int heightSize = sizeof(height) / sizeof(height[0]);
    int returnSize;

    int* result = stableMountains(height, heightSize, threshold, &returnSize);

    printf("Stable mountain indices: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free allocated memory
    free(result);

    return 0;
}
