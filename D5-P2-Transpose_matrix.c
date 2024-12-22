#include <stdio.h>
#include <stdlib.h>

// Function to transpose the matrix
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int new_row = *matrixColSize;   // Transposed rows equal to original columns
    int new_col = matrixSize;       // Transposed columns equal to original rows

    // Allocate memory for transposed matrix
    int** tMatrix = (int**)malloc(new_row * sizeof(int*));
    *returnColumnSizes = (int*)malloc(new_row * sizeof(int)); // Store column sizes for each row
    for (int i = 0; i < new_row; i++) {
        tMatrix[i] = (int*)malloc(new_col * sizeof(int));
        (*returnColumnSizes)[i] = new_col; // Set column sizes for each row in transposed matrix
    }

    *returnSize = new_row; // Number of rows in transposed matrix

    // Perform the transpose operation
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            tMatrix[j][i] = matrix[i][j]; // Swap rows and columns
        }
    }

    return tMatrix; // Return the transposed matrix
}

int main() {
    int rows, cols;

    // Input for the matrix dimensions
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Dynamically allocate memory for the matrix
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    // Input for the matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Transpose the matrix
    int returnSize;             // To store the number of rows in the transposed matrix
    int* returnColumnSizes;     // To store the column sizes of each row
    int** tMatrix = transpose(matrix, rows, &cols, &returnSize, &returnColumnSizes);

    // Print the transposed matrix
    printf("\nTransposed matrix:\n");
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", tMatrix[i][j]);
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < returnSize; i++) {
        free(tMatrix[i]);
    }
    free(tMatrix);
    free(returnColumnSizes);

    return 0;
}

