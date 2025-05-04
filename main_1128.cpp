#include "bits/stdc++.h"

using namespace std;

int numEquivDominoPairs(vector<vector<int>> &dominoes) {
    int res = 0;
    unordered_map<int, int> mp;
    for (const auto &d: dominoes) {
        int x = d[0] > d[1] ? d[0] * 10 + d[1] : d[1] * 10 + d[0];
        res += mp[x];
        mp[x]++;
    }
    return res;
}