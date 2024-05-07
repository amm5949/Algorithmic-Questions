#include <iostream>
using namespace std;
#define MAX 1000

int dp[MAX];


int solve(int n) {
    int result = 0;
    bool is_it_not_good_enough = true;
    int numbers = 1;
    while (is_it_not_good_enough) {
        int target = (numbers * (numbers + 1)) / 2;
        int count  = 0;
        for (int i = 1; i <= target; i++) {
            if (target % i == 0) {
                count++;
            }
        }
        if (count >= n) {
            is_it_not_good_enough = false;
            result = target;
        }
        // cout << target << endl;
        numbers++;
        
    }
    return result;
}

void initialization() {
    int len = sizeof(dp) / sizeof(dp[0]);

    for (int i = 0; i < len; i++) {
        dp[i] = -1;
    }
}

int generator (int n) {
    if (n == 1) {
        return 1;
    }
    else if (dp[n] != -1) {
        return dp[n];
    }
    return (dp[n] = n + generator(n - 1));
}

int main() {
    int n;
    cin >> n;
    // initialization();
    // generator(8);
    cout << solve(n) << endl;
    // for (int i = 1; i <= 300; i++) {
    //     cout << i << "- " << solve(i) << endl;
    // }
    
    return 0;
}