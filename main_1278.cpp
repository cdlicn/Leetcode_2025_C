#include "bits/stdc++.h"

using namespace std;

// TODO 1278. 分割回文串 III

vector<vector<int>> fMemo;
vector<vector<int>> memo;

int f(string s, int i, int j) {
    if (i >= j) {
        return 0;
    }
    int &res = fMemo[i][j];
    if (res != -1) {
        return res;
    }
    return res = f(s, i + 1, j - 1) + (s[i] != s[j]);
}

int dfs(string s, int i, int r) {
    if (i == 0) {
        return f(s, 0, r);
    }
    int &res = memo[i][r];
    if (res != -1) {
        return res;
    }
    res = INT_MAX;
    for (int l = i; l <= r; l++) {
        res = min(res, dfs(s, i - 1, l - 1) + f(s, l, r));
    }
    return res;
}

int palindromePartition(string s, int k) {
    int n = s.size();
    fMemo.resize(n, vector<int>(n, -1));
    memo.resize(k, vector<int>(n, -1));
    return dfs(s, k - 1, n - 1);
}