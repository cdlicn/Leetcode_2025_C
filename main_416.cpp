#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> memo;

bool dfs(int n, int i, vector<int> &nums) {
    if (i == nums.size()) {
        return n == 0;
    }
    int &res = memo[i][n];
    if (res != -1) {
        return res;
    }
    return res = (n >= nums[i] && dfs(n - nums[i], i + 1, nums)) || dfs(n, i + 1, nums);
}

bool canPartition(vector<int> &nums) {
    int sum = 0;
    for (const auto &num: nums) {
        sum += num;
    }
    memo.resize(nums.size(), vector<int>(sum / 2 + 1, -1));
    if (sum % 2) {
        return false;
    }
    return dfs(sum / 2, 0, nums);
}