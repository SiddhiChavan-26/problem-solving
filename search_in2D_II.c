#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to search for a target in the matrix
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if (matrixSize == 0 || matrixColSize[0] == 0) return false;

    int row = 0;                    
    int col = matrixColSize[0] - 1; 

    while (row < matrixSize && col >= 0) {
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] > target) {
            col--; 
        } else {
            row++; 
        }
    }
    return false;
}

// Main function
int main() {
    // Define matrix dimensions
    int matrixSize = 3; // Number of rows
    int matrixColSize[3] = {4, 4, 4}; // Number of columns for each row

    // Allocate memory for the matrix
    int** matrix = (int**)malloc(matrixSize * sizeof(int*));
    for (int i = 0; i < matrixSize; i++) {
        matrix[i] = (int*)malloc(matrixColSize[i] * sizeof(int));
    }

    // Initialize the matrix
    int values[3][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            matrix[i][j] = values[i][j];
        }
    }

    // Define target to search
    int target = 3;

    // Call the searchMatrix function
    bool result = searchMatrix(matrix, matrixSize, matrixColSize, target);

    // Print the result
    if (result) {
        printf("Target %d found in the matrix.\n", target);
    } else {
        printf("Target %d not found in the matrix.\n", target);
    }

    // Free allocated memory
    for (int i = 0; i < matrixSize; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

