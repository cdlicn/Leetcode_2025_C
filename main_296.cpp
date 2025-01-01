#include "bits/stdc++.h"

using namespace std;

// TODO 296. 最佳的碰头地点
int minTotalDistance(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<int> r, c;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                r.emplace_back(i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[j][i] == 1) {
                c.emplace_back(i);
            }
        }
    }
    int res = 0;
    int x = 0;
    int y = r.size() - 1;
    while (x < y) {
        res += r[y] - r[x];
        res += c[y] - c[x];
        x++;
        y--;
    }
    return res;
}