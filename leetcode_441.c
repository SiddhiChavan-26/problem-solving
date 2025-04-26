#include <stdio.h>

int arrangeCoins(int n) {
    long low = 0, high = n; // use long to prevent overflow during multiplication
    while (low <= high) {
        long mid = low + (high - low) / 2;
        long coins = (mid * (mid + 1)) / 2;
        
        if (coins == n)
            return (int)mid;
        else if (coins < n)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return (int)high;
}

int main() {
    int n;
    printf("Enter number of coins: ");
    scanf("%d", &n);
    
    int completeRows = arrangeCoins(n);
    printf("Number of complete rows: %d\n", completeRows);
    
    return 0;
}