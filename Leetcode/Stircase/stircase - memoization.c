#include <stdio.h>

int climbStairs(int n, int* dp) {
    // int dp[n];
    if (*dp != -1) {
        return dp[n];
    }
    int result;
    if (n==0) {
        result = 1;
    }
    else if (n==1) {
        result = 1;
    }
    else {
        return climbStairs(n - 1, dp) + climbStairs(n - 2, dp);
    }
    dp[n] = result;
    return result;
    //  dp[n];
}

int main() {
    int n, ways;
    
    scanf("%d", &n);
    int dp[n];
    for (int i = 0; i < n; i++) {
        dp[i] = -1;
    }

    ways = climbStairs(n, dp);
    printf("%d\n", ways);
    return 0;
}