#include "bits/stdc++.h"

using namespace std;

void sortF(vector<vector<int>> &grid, int x, int y, bool gr) {
    vector<int> diag;
    int n = grid.size();

    for (int i = x, j = y; i < n && j < n; ++i, ++j) {
        diag.push_back(grid[i][j]);
    }

    if (gr) {
        sort(diag.begin(), diag.end(), greater<int>());
    } else {
        sort(diag.begin(), diag.end());
    }

    for (int i = x, j = y, idx = 0; i < n && j < n; ++i, ++j, ++idx) {
        grid[i][j] = diag[idx];
    }
}

vector<vector<int>> sortMatrix(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    for (int r = 0; r < n; ++r) {
        sortF(grid, r, 0, true);
    }

    for (int c = 1; c < m; ++c) {
        sortF(grid, 0, c, false);
    }

    return grid;
}