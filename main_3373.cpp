#include "bits/stdc++.h"

using namespace std;

// TODO 3373. 连接两棵树后最大目标节点数目 II
vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2) {
    auto count = [](vector<vector<int>> &edges) {
        vector<vector<int>> g(edges.size() + 1);
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        array<int, 2> cnt{};
        auto dfs = [&](auto &&dfs, int x, int fa, int d) -> void {
            cnt[d]++;
            for (int y: g[x]) {
                if (y != fa) {
                    dfs(dfs, y, x, d ^ 1);
                }
            }
        };
        dfs(dfs, 0, -1, 0);
        return pair(g, cnt);
    };

    auto [_, cnt2] = count(edges2);
    int max2 = max(cnt2[0], cnt2[1]);

    auto [g, cnt1] = count(edges1);
    vector<int> ans(g.size(), max2);
    auto dfs = [&](auto &&dfs, int x, int fa, int d) -> void {
        ans[x] += cnt1[d];
        for (int y: g[x]) {
            if (y != fa) {
                dfs(dfs, y, x, d ^ 1);
            }
        }
    };
    dfs(dfs, 0, -1, 0);
    return ans;
}