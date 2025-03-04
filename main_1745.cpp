#include "bits/stdc++.h"

using namespace std;

// TODO 1745. 分割回文串 IV
int palindromePartition(string &s, int k) {
    int n = s.size();
    vector min_change(n, vector<int>(n));
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            min_change[i][j] = min_change[i + 1][j - 1] + (s[i] != s[j] ? 1 : 0);
        }
    }

    auto f = move(min_change[0]);
    for (int i = 1; i < k; i++) {
        for (int r = n - k + i; r >= i; r--) {
            f[r] = INT_MAX;
            for (int l = i; l <= r; l++) {
                f[r] = min(f[r], f[l - 1] + min_change[l][r]);
            }
        }
    }
    return f[n - 1];
}

bool checkPartitioning(string s) {
    return palindromePartition(s, 3) == 0;
}