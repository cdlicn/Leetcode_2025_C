#include "bits/stdc++.h"

using namespace std;

const int dis[4][2] = {
        {1,  0},
        {0,  1},
        {-1, 0},
        {0,  -1}
};

int swimInWater(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<vector<int>> l(n, vector<int>(n, INT_MAX));
    l[0][0] = grid[0][0];
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.emplace(grid[0][0], 0, 0);
    while (true) {
        auto [a, i, j] = pq.top();
        pq.pop();

        if (i == n - 1 && j == n - 1) {
            return a;
        }

        for (const auto &d: dis) {
            int x = i + d[0], y = j + d[1];
            if (x >= 0 && x < n && y >= 0 && y < n) {
                int distance = max(a, grid[x][y]);
                if (distance < l[x][y]) {
                    l[x][y] = distance;
                    pq.emplace(distance, x, y);
                }
            }
        }

    }
}