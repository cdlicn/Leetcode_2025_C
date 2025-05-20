#include "bits/stdc++.h"

using namespace std;

bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    vector<int> v(n + 1, 0);
    for (const auto &q: queries) {
        v[q[0]]++;
        v[q[1] + 1]--;
    }
    int add = 0;
    for (int i = 0; i < n; ++i) {
        add += v[i];
        if (add < nums[i]) {
            return false;
        }
    }
    return true;
}