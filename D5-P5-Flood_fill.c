#include<stdio.h>
#include <stdlib.h>

// Function to perform DFS for the flood fill
void floodFillDFS(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int startColor) {
    // Base case: Check bounds and whether the pixel has the same color
    if (sr < 0 || sr >= imageSize || sc < 0 || sc >= imageColSize[sr] || image[sr][sc] != startColor || image[sr][sc] == newColor) {
        return;
    }
    
    image[sr][sc] = newColor;

    // Perform DFS in all four directions
    floodFillDFS(image, imageSize, imageColSize, sr + 1, sc, newColor, startColor); // Down
    floodFillDFS(image, imageSize, imageColSize, sr - 1, sc, newColor, startColor); // Up
    floodFillDFS(image, imageSize, imageColSize, sr, sc + 1, newColor, startColor); // Right
    floodFillDFS(image, imageSize, imageColSize, sr, sc - 1, newColor, startColor); // Left
}

// Main Flood Fill function
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes) {
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    // Get the starting pixel color
    int startColor = image[sr][sc];

    // If the starting pixel color is already the new color, no operation is needed
    if (startColor != newColor) {
        floodFillDFS(image, imageSize, imageColSize, sr, sc, newColor, startColor);
    }

    return image;
}
int main() {
    int imageSize = 3; // Number of rows
    int imageColSize[] = {3, 3, 3}; // Number of columns for each row

    // Input image
    int imageData[3][3] = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    // Dynamically allocate memory for the image (2D array)
    int** image = (int**)malloc(imageSize * sizeof(int*));
    for (int i = 0; i < imageSize; i++) {
        image[i] = (int*)malloc(imageColSize[i] * sizeof(int));
        for (int j = 0; j < imageColSize[i]; j++) {
            image[i][j] = imageData[i][j];
        }
    }

    // Starting point and new color
    int sr = 1; // Starting row
    int sc = 1; // Starting column
    int newColor = 2; // New color to apply

    int returnSize; // Output variable for the number of rows
    int* returnColumnSizes; // Output variable for column sizes of each row

    // Perform flood fill
    int** result = floodFill(image, imageSize, imageColSize, sr, sc, newColor, &returnSize, &returnColumnSizes);

    // Print the resulting image
    printf("Modified Image:\n");
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    for (int i = 0; i < imageSize; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}
