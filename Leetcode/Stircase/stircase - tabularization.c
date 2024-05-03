#include <stdio.h>


int climbStairs(int n) {
    int dp[n + 1];
    int result;
    if (n <= 1) {
        return 1;
    }
    
    else {
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    
    //  dp[n];
}


int main() {
    int n, ways;
    ways = 0;
    scanf("%d", &n);
    ways = climbStairs(n);

    printf("%d", ways);
    return 0;
}