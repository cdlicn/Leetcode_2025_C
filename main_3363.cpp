#include "bits/stdc++.h"

using namespace std;

int maxCollectedFruits(vector<vector<int>> &fruits) {
    int n = fruits.size();
    vector memo(n, vector<int>(n, -1));
    auto dfs = [&](this auto &&dfs, int i, int j) -> int {
        if (j < n - 1 - i || j >= n) {
            return 0;
        }
        if (i == 0) {
            return fruits[i][j];
        }
        int &res = memo[i][j];
        if (res != -1) {
            return res;
        }
        return res = max({dfs(i - 1, j - 1), dfs(i - 1, j), dfs(i - 1, j + 1)}) + fruits[i][j];
    };

    int res = 0;
    for (int i = 0; i < n; i++) {
        res += fruits[i][i];
    }

    res += dfs(n - 2, n - 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            fruits[j][i] = fruits[i][j];
        }
    }
    ranges::fill(memo, vector(n, -1));
    return res + dfs(n - 2, n - 1);
}