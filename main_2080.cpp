#include "bits/stdc++.h"

using namespace std;

class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> mp;

    RangeFreqQuery(vector<int> &arr) {
        for (int i = 0; i < arr.size(); ++i) {
            mp[arr[i]].emplace_back(i);
        }
    }

    int query(int left, int right, int value) {
        auto l = lower_bound(mp[value].begin(), mp[value].end(), left);
        auto r = upper_bound(mp[value].begin(), mp[value].end(), right);
        return r - l;
    }
};