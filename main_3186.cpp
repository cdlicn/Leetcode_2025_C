#include "bits/stdc++.h"

using namespace std;

// TODO 3186. 施咒的最大总伤害
long long maximumTotalDamage(vector<int> &power) {
    unordered_map<int, int> cnt;
    for (int x: power) {
        cnt[x]++;
    }
    vector<pair<int, int>> a(cnt.begin(), cnt.end());
    ranges::sort(a);

    int n = a.size();
    vector<long long> dp(n + 1);
    for (int i = 0, j = 0; i < n; i++) {
        auto &[x, c] = a[i];
        while (a[j].first < x - 2) {
            j++;
        }
        dp[i + 1] = max(dp[i], dp[j] + (long long) x * c);
    }
    return dp[n];
}