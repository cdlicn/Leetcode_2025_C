#include "bits/stdc++.h"

using namespace std;

int minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();
    if (n == 1) {
        return triangle[0][0];
    }
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 2));
    dp[0][0] = triangle[0][0];
    int res = INT_MAX;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = min(dp[i - 1][j], j - 1 >= 0 ? dp[i - 1][j - 1] : INT_MAX / 2) + triangle[i][j];
            if (i == n - 1) {
                res = min(res, dp[i][j]);
            }
        }
    }
    return res;
}