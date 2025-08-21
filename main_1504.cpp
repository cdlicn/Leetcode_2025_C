#include "bits/stdc++.h"

using namespace std;

int numSubmat(vector<vector<int>> &mat) {
    int res = 0;
    int m = mat.size();
    int n = mat[0].size();
    for (int t = 0; t < m; ++t) {
        vector<int> v(n + 1);
        for (int b = t; b < m; ++b) {
            int h = b - t + 1;
            int last = -1;
            for (int j = 0; j < n; j++) {
                v[j] += mat[b][j];
                if (v[j] != h) {
                    last = j;
                } else {
                    res += j - last;
                }
            }
        }
    }
    return res;
}