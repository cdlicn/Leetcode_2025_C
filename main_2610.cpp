#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> findMatrix(vector<int> &nums) {
    vector<vector<int>> res;
    unordered_map<int, int> mp;
    for (const auto &num: nums) {
        int &x = mp[num];
        if (x >= res.size()) {
            res.emplace_back();
        }
        res[x].emplace_back(num);
        x++;
    }
    return res;
}