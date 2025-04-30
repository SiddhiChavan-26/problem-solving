#include <stdio.h>

struct CoinResult {
    int count;
    int coinsUsed[100];
};

struct CoinResult coins(int coins[], int amount, int n) {
    int i, j, temp = 0, count = 0;
    struct CoinResult result; 
    
 
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (coins[i] < coins[j]) {
                temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    
    i = 0;
    j = 0;
    while (i < n && amount > 0) {
        if (amount >= coins[i]) {
            amount -= coins[i];
            count++;
            result.coinsUsed[j] = coins[i];
            j++;
        } else {
            i++;
        }
    }

    result.count = count; 
    return result; 

int main() {
    int n;
    struct CoinResult result;
    printf("Enter the number of coins you already have: ");
    scanf("%d", &n);
    
    int coin[n], i;
    printf("Enter the coins: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
    }
    
    int amount;
    printf("Enter the amount: ");
    scanf("%d", &amount);
    
    result = 3.coins(coin, amount, n);
    

    printf("The total number of coins are: %d\n", result.count);
    printf("The coins used are: ");
    for (i = 0; i < result.count; i++) {
        printf("%d ", result.coinsUsed[i]);
    }
    printf("\n");
    
    return 0;
}

