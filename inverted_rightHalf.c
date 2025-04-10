// Inverted right half pyramid of stars using C
#include <stdio.h>

int main()
{
    int rows = 7;

    // first loop to print all rows
    for (int i = 0; i < rows; i++) {

        // first inner loop to print the * in each row
        for (int j = 0; j < rows - i; j++) {
            printf("* ");
        }
        printf("");
    }
}