#include <stdio.h>
#include <stdlib.h>

// Helper function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

int coinChange(int* coins, int coinsSize, int amount) {
    // Create DP array and fill with a large value representing infinity
    int* dp = (int*)malloc((amount + 1) * sizeof(int));
    int max_val = amount + 1; // Amount + 1 is impossible to reach, acts as infinity
    
    dp[0] = 0; // Base case: 0 coins needed to make amount 0
    for (int i = 1; i <= amount; i++) {
        dp[i] = max_val;
    }

    // Build the DP table bottom-up
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    int result = dp[amount];
    free(dp); // Prevent memory leaks

    // If target amount is still infinity, it's impossible to make that amount
    return (result > amount) ? -1 : result;
}

// Boilerplate main function to run inside VS Code
int main() {
    int coins[] = {1, 2, 5};
    int coinsSize = sizeof(coins) / sizeof(coins[0]);
    int amount = 11;

    int result = coinChange(coins, coinsSize, amount);
    printf("Minimum coins required for amount %d: %d\n", amount, result);

    return 0;
}
