#include "bits/stdc++.h"

using namespace std;

vector<int> memo;

int dfs(vector<int> &prices, int i) {
    if (i * 2 >= prices.size()) {
        return prices[i - 1];
    }
    int &res = memo[i];
    if (res) {
        return res;
    }
    res = INT_MAX;
    for (int j = i + 1; j <= i * 2 + 1; j++) {
        res = min(res, dfs(prices, j));
    }
    res += prices[i - 1];
    return res;
}

int minimumCoins(vector<int> &prices) {
    int n = prices.size();
    memo.resize((n + 1) / 2);
    return dfs(prices, 1);
}