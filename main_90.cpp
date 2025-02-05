#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> res;

void dfs(vector<int> &nums, vector<int> v, int i) {
    if (i == nums.size()) {
        res.push_back(v);
        return;
    }
    v.push_back(nums[i]);
    dfs(nums, v, i + 1);
    v.erase(v.end());
    while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
        i++;
    }
    dfs(nums, v, i + 1);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    dfs(nums, vector<int>(0), 0);
    return res;
}