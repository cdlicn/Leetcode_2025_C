#include "bits/stdc++.h"

using namespace std;

// TODO 1857. 有向图中最大颜色值
int largestPathValue(string colors, vector<vector<int>> &edges) {
    int n = colors.size();
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (auto &e: edges) {
        int x = e[0], y = e[1];
        if (x == y) { // 自环
            return -1;
        }
        g[x].push_back(y);
        deg[y]++;
    }

    vector<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.push_back(i); // 入度为 0 的点入队
        }
    }

    int ans = 0;
    vector<array<int, 26>> f(n);
    for (int i = 0; i < q.size(); i++) { // 注意 q.size() 会变大
        int x = q[i]; // x 的所有转移来源都计算完毕，也都更新到 f[x] 中
        int ch = colors[x] - 'a';
        f[x][ch]++;
        ans = max(ans, f[x][ch]);
        for (int y: g[x]) {
            for (int j = 0; j < 26; j++) {
                f[y][j] = max(f[y][j], f[x][j]); // 刷表法，更新邻居的最大值
            }
            if (--deg[y] == 0) {
                q.push_back(y);
            }
        }
    }

    return q.size() < n ? -1 : ans;
}