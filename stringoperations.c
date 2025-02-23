#include <stdio.h>
#include <string.h>

// Function to find the length of a string
int findLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to replace a specified character with another character
void replace(char str[], char old, char new) {
	int i;
    for ( i = 0; str[i] != '\0'; i++) {
        if (str[i] == old) {
            str[i] = new;
        }
    }
}

// Function to remove spaces from a string
void removeSpaces(char str[]) {
    int i, j = 0;
    char temp[strlen(str) + 1];
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            temp[j] = str[i];
            j++;
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

int main() {
    char str[100], old, new;

    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    int length = findLength(str);
    printf("Length of the string: %d\n", length);

    // Input characters to replace
    printf("Enter the character to be replaced: ");
    scanf(" %c", &old);
    printf("Enter the new character: ");
    scanf(" %c", &new);

    // Replacing the specified character
    replace(str, old, new);
    printf("String after replacing '%c' with '%c': %s\n", old, new, str);

    // Removing spaces from the string
    removeSpaces(str);
    printf("String after removing spaces: %s\n", str);

    return 0;
}
