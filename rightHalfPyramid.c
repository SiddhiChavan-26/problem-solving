//Right half pyramid pattern of stars using C
#include <stdio.h>

int main()
{
    int rows = 7;

    // first loop for printing rows
    for (int i = 0; i < rows; i++) {

        // second loop for printing character in each rows
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("");
    }
    return 0;
}