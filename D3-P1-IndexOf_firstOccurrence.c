#include <stdio.h>
#include <string.h>

int first_occur(char* haystack, char* needle) {
    int len_haystack = strlen(haystack);
    int len_needle = strlen(needle);
	
    if (len_needle == 0) {
        return 0; 
    }
    
    for (int  i = 0; i <= len_haystack - len_needle; i++) {
        int found = 1; 
        for (int j = 0; j < len_needle; j++) {
            if (haystack[i + j] != needle[j]) {
                found = 0; 
                break;
            }
        }
        if (found) {
            return i; 
        }
    }

    return -1; 
}

int main() {
    char haystack[100], needle[100];

    printf("Enter the haystack string: ");
    scanf("%s", haystack);

    printf("Enter the needle string: ");
    scanf("%s", needle);

    int result = first_occur(haystack, needle);

    if (result != -1) {
        printf("The first occurrence of '%s' in '%s' is at index %d.\n", needle, haystack, result);
    } else {
        printf("The string '%s' does not occur in '%s'.\n", needle, haystack);
    }

    return 0;
}




