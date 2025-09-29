#include "bits/stdc++.h"

using namespace std;

int minScoreTriangulation(vector<int> &values) {
    int n = values.size();
    vector f(n, vector<int>(n));
    for (int i = n - 3; i >= 0; i--) {
        for (int j = i + 2; j < n; j++) {
            f[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j] + values[i] * values[j] * values[k]);
            }
        }
    }
    return f[0][n - 1];
}