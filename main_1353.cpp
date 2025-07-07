#include "bits/stdc++.h"

using namespace std;

int maxEvents(vector<vector<int>> &events) {
    int n = 0;
    for (const auto &e: events) {
        n = max(n, e[1]);
    }
    vector<vector<int>> v(n + 1);
    for (const auto &e: events) {
        v[e[0]].emplace_back(e[1]);
    }

    int res = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i <= n; ++i) {
        while (!pq.empty() && pq.top() < i) {
            pq.pop();
        }
        for (const auto &e: v[i]) {
            pq.emplace(e);
        }
        if (!pq.empty()) {
            pq.pop();
            res++;
        }
    }
    return res;
}