#include <stdio.h>
#include <stdlib.h>

int scoreOfString(char* s) {
    int score = 0;
    for (int i = 1; s[i] != '\0'; i++) {
        score += abs(s[i] - s[i - 1]);
    }
    return score;
}

int main() {
    char s[] = "hello";
    int result = scoreOfString(s);
    printf("Score of string: %d\n", result);
    return 0;
}

