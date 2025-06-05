#include "bits/stdc++.h"

using namespace std;

class UnionFind {
private:
    std::vector<int> fa;

public:
    UnionFind(int N) : fa(N) { init(N); }

    void init(int N) {
        fa.resize(N);
        for (int i = 0; i < N; i++) {
            fa[i] = i;
        }
    }

    int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }

    void unionSets(int x, int y) {
        auto [small, big] = minmax(find(x), find(y));
        fa[big] = small;
    }
};

string smallestEquivalentString(string s1, string s2, string baseStr) {
    int n = s1.size();
    UnionFind uf(26);
    for (int i = 0; i < n; ++i) {
        uf.unionSets(s1[i] - 'a', s2[i] - 'a');
    }
    for (int i = 0; i < baseStr.size(); ++i) {
        baseStr[i] = uf.find(baseStr[i] - 'a') + 'a';
    }
    return baseStr;
}