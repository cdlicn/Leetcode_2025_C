#include "bits/stdc++.h"

using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>> &mat) {
    int idx = -1, cnt = 0;
    int m = mat.size(), n = mat[0].size();
    for (int i = 0; i < m; ++i) {
        int s = 0;
        for (int j = 0; j < n; ++j) {
            s += mat[i][j] == 1;
        }
        if (s > cnt) {
            cnt = s;
            idx = i;
        }
    }
    return {idx, cnt};
}