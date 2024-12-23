#include <stdio.h>
#include <stdlib.h>
int findMaxInColumn(int** matrix, int matrixSize, int col) {
    int maxVal = 0;
    for (int i = 0; i < matrixSize; i++) {
        if (matrix[i][col] > maxVal) {
            maxVal = matrix[i][col];
        }
    }
    return maxVal;
}

int** modifiedMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int rows = matrixSize;
    int cols = *matrixColSize;

    // Allocate memory for the modified matrix
    int** result = (int**)malloc(rows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(rows * sizeof(int));

    for (int i = 0; i < rows; i++) {
        result[i] = (int*)malloc(cols * sizeof(int));
        (*returnColumnSizes)[i] = cols;

        for (int j = 0; j < cols; j++) {
            // Replace -1 with the maximum value in the column
            if (matrix[i][j] == -1) {
                result[i][j] = findMaxInColumn(matrix, rows, j);
            } else {
                result[i][j] = matrix[i][j];
            }
        }
    }

    *returnSize = rows;
    return result;
}

// Helper function to input a matrix
int** inputMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}

// Helper function to print a matrix
void printMatrix(int** matrix, int rows, int* colSizes) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colSizes[i]; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Input the matrix
    printf("Enter the matrix elements (-1 for special replacement):\n");
    int** matrix = inputMatrix(rows, cols);

    // Print the original matrix
    printf("Original Matrix:\n");
    int* colSizes = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) colSizes[i] = cols;
    printMatrix(matrix, rows, colSizes);

    // Modify the matrix
    int returnSize;
    int* returnColumnSizes;
    int** modified = modifiedMatrix(matrix, rows, &cols, &returnSize, &returnColumnSizes);

    // Print the modified matrix
    printf("Modified Matrix:\n");
    printMatrix(modified, returnSize, returnColumnSizes);

    // Free dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
        free(modified[i]);
    }
    free(matrix);
    free(modified);
    free(colSizes);
    free(returnColumnSizes);

    return 0;
}

