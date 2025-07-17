#include "bits/stdc++.h"

using namespace std;

int maximumLength(vector<int> &nums, int k) {
    int n = nums.size();
    vector<vector<int>> dp(k, vector<int>(n, 1));
    int res = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int m = (nums[i] + nums[j]) % k;
            dp[m][i] = max(dp[m][j] + 1, dp[m][j]);
            res = max(res, dp[m][i]);
        }
    }
    return res;
}