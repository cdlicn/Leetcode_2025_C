#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> res;

void dfs(vector<int> &nums, vector<int> visited, vector<int> add) {
    if (add.size() == nums.size()) {
        res.push_back(add);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) {
            continue;
        }
        add.push_back(nums[i]);
        visited[i] = true;
        dfs(nums, visited, add);
        add.erase(add.end());
        visited[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    dfs(nums, vector<int>(nums.size(), false), vector<int>());
    return res;
}