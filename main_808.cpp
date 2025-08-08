#include "bits/stdc++.h"

using namespace std;

double soupServings(int n) {
    if (n >= 4451) {
        return 1;
    }
    n = (n + 24) / 25;
    vector<vector<double>> memo(n + 1, vector<double>(n + 1, 0));
    auto dfs = [&](this auto &&dfs, int a, int b) -> double {
        if (a <= 0 && b <= 0) {
            return 0.5;
        }
        if (a <= 0) {
            return 1;
        }
        if (b <= 0) {
            return 0;
        }
        double &res = memo[a][b];
        if (res == 0) {
            res = (dfs(a - 4, b) + dfs(a - 3, b - 1) + dfs(a - 2, b - 2) + dfs(a - 1, b - 3)) / 4;
        }
        return res;
    };
    return dfs(n, n);
}