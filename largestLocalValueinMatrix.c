/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int n = gridSize;
    int outSize = n - 2;

    int** maxLocal = (int**)malloc(outSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(outSize * sizeof(int));
    for (int i = 0; i < outSize; ++i) {
        maxLocal[i] = (int*)malloc(outSize * sizeof(int));
        (*returnColumnSizes)[i] = outSize;
    }

    for (int i=0; i < n-2; ++i){
        for(int j=0; j < n-2; ++j){
            int maxVal = INT_MIN;
            for(int x = i; x <= i+2; ++x){
                for(int y = j; y <= j+2; ++y){
                    if(grid[x][y] > maxVal){
                        maxVal = grid[x][y];
                    }
                }
            }
            maxLocal[i][j] =  maxVal;
        }
    }
    *returnSize = outSize;
    return maxLocal;
}
int main() {
    int n = 4;
    
    // Static 2D array data
    int data[4][4] = {
        {9, 9, 8, 1},
        {5, 6, 2, 6},
        {8, 2, 6, 4},
        {6, 2, 2, 2}
    };

    // Convert to dynamic int**
    int** grid = (int**)malloc(n * sizeof(int*));
    int* gridColSize = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        grid[i] = (int*)malloc(n * sizeof(int));
        gridColSize[i] = n;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = data[i][j];
        }
    }

    int returnSize;
    int* returnColumnSizes;
    int** result = largestLocal(grid, n, gridColSize, &returnSize, &returnColumnSizes);

    // Print the result
    printf("Resultant maxLocal matrix:\n");
    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < returnColumnSizes[i]; ++j) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < n; ++i) {
        free(grid[i]);
    }
    free(grid);
    free(gridColSize);

    for (int i = 0; i < returnSize; ++i) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}
 
