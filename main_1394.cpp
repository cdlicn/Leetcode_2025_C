#include "bits/stdc++.h"

using namespace std;

int findLucky(vector<int> &arr) {
    unordered_map<int, int> mp;
    for (const auto &v: arr) {
        mp[v]++;
    }
    int res = -1;
    for (const auto &[k, v]: mp) {
        k == v ? res = max(res, v) : -1;
    }
    return res;
}