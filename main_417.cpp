#include "bits/stdc++.h"

using namespace std;

const int dis[4][2] = {
        {0,  1},
        {0,  -1},
        {1,  0},
        {-1, 0}
};

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int m = heights.size(), n = heights[0].size();


    auto dfs = [&](this auto &&dfs, int i, int j, vector<vector<bool>> &visited, int bef) -> void {
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || heights[i][j] < bef) {
            return;
        }
        visited[i][j] = true;
        for (const auto &d: dis) {
            dfs(i + d[0], j + d[1], visited, heights[i][j]);
        }
    };

    vector<vector<bool>> p_visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        dfs(i, 0, p_visited, 0);
    }
    for (int j = 0; j < n; j++) {
        dfs(0, j, p_visited, 0);
    }

    vector<vector<bool>> a_visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        dfs(i, n - 1, a_visited, 0);
    }
    for (int j = 0; j < n; j++) {
        dfs(m - 1, j, a_visited, 0);
    }

    vector<vector<int>> res;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a_visited[i][j] && p_visited[i][j]) {
                res.emplace_back(vector{i, j});
            }
        }
    }

    return res;
}