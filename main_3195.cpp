#include "bits/stdc++.h"

using namespace std;

int minimumArea(vector<vector<int>> &grid) {
    int left = INT_MAX, right = -1, top = INT_MAX, bottom = -1;
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j]) {
                left = min(left, j);
                top = min(top, i);
                right = max(right, j);
                bottom = max(bottom, i);
            }
        }
    }
    return (right - left + 1) * (bottom - top + 1);
}