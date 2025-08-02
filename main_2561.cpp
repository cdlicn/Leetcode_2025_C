#include "bits/stdc++.h"

using namespace std;

long long minCost(vector<int> &basket1, vector<int> &basket2) {
    unordered_map<int, int> mp;
    int n = basket1.size();
    for (int i = 0; i < n; ++i) {
        mp[basket1[i]]++;
        mp[basket2[i]]--;
    }

    int mn = INT_MAX;
    vector<int> a, b;
    for (const auto &[k, v]: mp) {
        if (v % 2) {
            return -1;
        }
        mn = min(mn, k);
        if (v > 0) {
            for (int i = 0; i < v / 2; ++i) {
                a.emplace_back(k);
            }
        } else {
            for (int i = 0; i < -v / 2; ++i) {
                b.emplace_back(k);
            }
        }
    }

    long long res = 0;
    ranges::sort(a);
    ranges::sort(b, greater());
    for (int i = 0; i < a.size(); ++i) {
        res += min({2 * mn, a[i], b[i]});
    }
    return res;
}