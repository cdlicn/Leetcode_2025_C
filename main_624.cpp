#include "bits/stdc++.h"

using namespace std;

int maxDistance(vector<vector<int>> &arrays) {
    int mx = INT_MIN >> 1, mn = INT_MAX >> 1;
    int res = 0;
    for (const auto &array: arrays) {
        res = max({res, array.back() - mn, mx - array[0]});
        mx = max(mx, array.back());
        mn = min(mn, array[0]);
    }
    return res;
}