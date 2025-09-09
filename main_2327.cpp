#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;

int peopleAwareOfSecret(int n, int delay, int forget) {
    vector<int> dp(n + 1);
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int add = (dp[max(i - delay, 0)] - dp[max(i - forget, 0)]) % MOD;
        dp[i] = (dp[i - 1] + add) % MOD;
    }
    int res = dp[n] - dp[max(n - forget, 0)];
    return (res % MOD + MOD) % MOD;
}