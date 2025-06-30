#include "bits/stdc++.h"

using namespace std;

int findLHS(vector<int> &nums) {
    unordered_map<int, int> mp;
    for (const auto &num: nums) {
        mp[num]++;
    }
    int res = 0;
    for (const auto &[k, v]: mp) {
        if (mp.contains(k + 1)) {
            res = max(res, v + mp[k + 1]);
        }
    }
    return res;
}