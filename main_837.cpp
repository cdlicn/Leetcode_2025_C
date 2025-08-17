#include "bits/stdc++.h"

using namespace std;

double new21Game(int n, int k, int maxPts) {
    vector<double> dp(n + maxPts);
    double s = 0;
    for (int i = k; i < k + maxPts && i <= n; i++) {
        dp[i] = 1;
        s++;
    }
    for (int i = k - 1; i >= 0; i--) {
        dp[i] = s / maxPts;
        s = s - dp[i + maxPts] + dp[i];
    }
    return dp[0];
}