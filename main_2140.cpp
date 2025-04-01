#include "bits/stdc++.h"

using namespace std;

long long mostPoints(vector<vector<int>> &questions) {
    int n = questions.size();
    vector<long long> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = max(dp[i + 1], dp[min(i + questions[i][1] + 1, n)] + questions[i][0]);
    }
    return dp[0];
}