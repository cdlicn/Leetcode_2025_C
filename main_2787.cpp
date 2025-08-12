#include "bits/stdc++.h"

using namespace std;

int numberOfWays(int n, int x) {
    vector<long long> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int v = pow(i, x);
        for (int j = n; j >= v; j--) {
            dp[j] += dp[j - v];
        }
    }
    return dp[n] % 1000000007;
}