#include <stdio.h>
#include <stdbool.h>

bool isPerfectSquare(int num) {
    int low = 0, high = num;
    while (low <= high) {
        long mid = low + (high - low) / 2;
        if (mid*mid == num) {
            return true;
        } else if (mid*mid > num) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return false;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPerfectSquare(num)) {
        printf("%d is a perfect square.\n", num);
    } else {
        printf("%d is not a perfect square.\n", num);
    }

    return 0;
}