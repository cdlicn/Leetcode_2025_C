#include "bits/stdc++.h"

using namespace std;

int res = -1;
unordered_map<int, int> mp;

void dfs(vector<int> &nums, int k, int i) {
    res++;
    if (i == nums.size()) {
        return;
    }
    for (int j = i; j < nums.size(); j++) {
        int x = nums[j];
        if (mp[x - k] == 0 && mp[x + k] == 0) {
            mp[x]++;
            dfs(nums, k, j + 1);
            mp[x]--;
        }
    }
}

int beautifulSubsets(vector<int> &nums, int k) {
    dfs(nums, k, 0);
    return res;
}