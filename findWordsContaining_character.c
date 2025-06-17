#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
    int* result = (int*)malloc(wordsSize * sizeof(int));  // Max possible size

    int k = 0;
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; words[i][j] != '\0'; j++) {
            if (words[i][j] == x) {
                result[k++] = i;
                break;  
            }
        }
    }

    *returnSize = k;
    return result;
}

int main() {
    // Sample word list
    char* words[] = {"apple", "banana", "grape", "kiwi", "mango"};
    int wordsSize = sizeof(words) / sizeof(words[0]);
    char searchChar;

    // Input the character to search
    printf("Enter a letter to search for: ");
    scanf(" %c", &searchChar);  // space before %c to handle newline

    // Call the function
    int returnSize;
    int* result = findWordsContaining(words, wordsSize, searchChar, &returnSize);

    // Display results
    if (returnSize == 0) {
        printf("No words contain the letter '%c'.\n", searchChar);
    } else {
        printf("Words containing the letter '%c':\n", searchChar);
        for (int i = 0; i < returnSize; i++) {
            printf("Index %d: %s\n", result[i], words[result[i]]);
        }
    }

    // Free memory
    free(result);

    return 0;
}

