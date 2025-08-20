#include "bits/stdc++.h"

using namespace std;

int countSquares(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> f(m + 1, vector<int>(n + 1));
    int res = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j]) {
                f[i + 1][j + 1] = min({f[i + 1][j], f[i][j + 1], f[i][j]}) + 1;
                res += f[i + 1][j + 1];
            }
        }
    }
    return res;
}