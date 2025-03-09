#include "bits/stdc++.h"

using namespace std;


vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
    auto cmp = [&](vector<int> a, vector<int> b) {
        return a[0] < b[0];
    };
    auto cmpIdx = [&](int a, int b) {
        return queries[a] < queries[b];
    };
    sort(items.begin(), items.end(), cmp);
    vector<int> res(queries.size(), 0);
    vector<int> idx(queries.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), cmpIdx);
    int mx = 0, j = 0;
    for (int i: idx) {
        int q = queries[i];
        while (j < items.size() && items[j][0] <= q) {
            mx = max(mx, items[j][1]);
            j++;
        }
        res[i] = mx;
    }
    return res;
}