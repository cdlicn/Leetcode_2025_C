#include "bits/stdc++.h"

using namespace std;

class UnionFind {
public:
    vector<int> parent;
    int num;

    UnionFind(int n) {
        parent.resize(n);
        num = n;
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unit(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        parent[x] = y;
        num--;
    }
};

int minCost(int n, vector<vector<int>> &edges, int k) {
    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });
    UnionFind uf(n);
    int mx = 0;
    for (auto& edge : edges) {
        if (uf.num == k) {
            break;
        }
        if (uf.find(edge[0]) != uf.find(edge[1])) {
            uf.unit(edge[0], edge[1]);
            mx = max(mx, edge[2]);
        }
    }
    return mx;
}