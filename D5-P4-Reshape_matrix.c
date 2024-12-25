#include <stdio.h>
#include <stdlib.h>

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int originalRows = matSize;
    int originalCols = *matColSize;

    // Check if reshaping is possible
    if (originalRows * originalCols != r * c) {
        *returnSize = originalRows;
        *returnColumnSizes = (int*)malloc(originalRows * sizeof(int));
        for (int i = 0; i < originalRows; i++) {
            (*returnColumnSizes)[i] = originalCols;
        }
        return mat; // Return original matrix if reshaping is not possible
    }

    // Allocate memory for the reshaped matrix
    int** reshapedMatrix = (int**)malloc(r * sizeof(int*));
    *returnColumnSizes = (int*)malloc(r * sizeof(int));
    for (int i = 0; i < r; i++) {
        reshapedMatrix[i] = (int*)malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c; // Set the column size for each row
    }

    // Perform reshaping
    for (int i = 0; i < originalRows * originalCols; i++) {
        reshapedMatrix[i / c][i % c] = mat[i / originalCols][i % originalCols];
    }

    *returnSize = r; // Set the number of rows in the reshaped matrix
    return reshapedMatrix;
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
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n;

    // Input for original matrix dimensions
    printf("Enter row size and column size of the original matrix: ");
    scanf("%d %d", &m, &n);

    // Input matrix
    printf("Enter matrix elements:\n");
    int** mat = inputMatrix(m, n);

    // Input for reshaped matrix dimensions
    int r, c;
    printf("Enter reshaped row size and column size: ");
    scanf("%d %d", &r, &c);

    // Reshape the matrix
    int returnSize;
    int* returnColumnSizes;
    int** reshapedMatrix = matrixReshape(mat, m, &n, r, c, &returnSize, &returnColumnSizes);

    // Display the reshaped matrix
    printf("\nReshaped Matrix:\n");
    printMatrix(reshapedMatrix, returnSize, returnColumnSizes);

    // Free dynamically allocated memory
    for (int i = 0; i < m; i++) {
        free(mat[i]);
    }
    free(mat);

    for (int i = 0; i < returnSize; i++) {
        free(reshapedMatrix[i]);
    }
    free(reshapedMatrix);
    free(returnColumnSizes);

    return 0;
}

