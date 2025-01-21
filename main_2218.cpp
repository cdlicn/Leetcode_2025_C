#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> memo;

int dfs(vector<vector<int>> &piles, int i, int j) {
    if (i < 0) {
        return 0;
    }
    int &res = memo[i][j];
    if (res) {
        return res;
    }
    res = dfs(piles, i - 1, j);
    int v = 0;
    for (int w = 0; w < min(j, (int) piles[i].size()); w++) {
        v += piles[i][w];
        res = max(res, dfs(piles, i - 1, j - w - 1) + v);
    }
    return res;
}


int maxValueOfCoins(vector<vector<int>> &piles, int k) {
    int n = piles.size();
    memo.resize(n, vector<int>(k + 1));
    return dfs(piles, n - 1, k);
}