//Floyd's Triangle Pattern using C
#include <stdio.h>

int main()
{
    int rows = 10;  
    int n = 1;      

    // Calculate the width of the largest number in Floyd's triangle
    // This is important for maintaining proper alignment in the triangle
    // Especially when we have numbers with more than one digit.
    
    int width = 0;

    // Calculate the last number in the triangle using the formula n(n+1)/2
    int lastNumber = rows * (rows + 1) / 2;

    // Calculate the number of digits in the last number. This will determine
    // the width required for proper alignment.
    while (lastNumber) {
        width++;          
        lastNumber /= 10;
    }

    // Outer loop to handle each row of the triangle
    for (int i = 0; i < rows; i++) {

        // Inner loop to print numbers in each row. 
        for (int j = 0; j <= i; j++) {

            // Print each number, using width to ensure proper spacing.
            // "%-*d" is a format specifier where '*' allows dynamic width 
            // specification. The '-' ensures left alignment.
            printf("%-*d ", width, n++);  
        }

        printf("");
    }

    return 0;
}