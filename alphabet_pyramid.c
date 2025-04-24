#include <stdio.h>

int main() {
    int rows = 5, i, j, space;
    char ch = 'A';
    for (i = 1; i <= rows; i++) {
        for (space = 1; space <= rows - i; space++)
            printf(" ");
        ch = 'A';
        for (j = 1; j <= 2 * i - 1; j++)
            printf("%c", ch++);
        printf("\n");
    }
    return 0;
}