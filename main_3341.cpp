#include "bits/stdc++.h"

using namespace std;

int minTimeToReach(vector<vector<int>> &moveTime) {
    int dirs[4][2] = {{-1, 0},
                      {1,  0},
                      {0,  -1},
                      {0,  1}};
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.emplace(0, 0, 0);
    int m = moveTime.size(), n = moveTime[0].size();
    vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
    while (!pq.empty()) {
        auto [v, x, y] = pq.top();
        pq.pop();
        if (x == m - 1 && y == n - 1) {
            return v;
        }
        if (v > dis[x][y]) {
            continue;
        }
        for (auto &dir: dirs) {
            int i = x + dir[0], j = y + dir[1];
            if (0 <= i && i < m && 0 <= j && j < n) {
                int nxV = max(v, moveTime[i][j]) + 1;
                if (nxV < dis[i][j]) {
                    dis[i][j] = nxV;
                    pq.emplace(nxV, i, j);
                }
            }
        }
    }
    return -1;
}