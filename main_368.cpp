#include "bits/stdc++.h"

using namespace std;

vector<int> memo, from_;

int dfs(vector<int> &nums, int i) {
    int &res = memo[i];
    if (res) {
        return res;
    }
    for (int j = 0; j < i; ++j) {
        if (nums[i] % nums[j]) {
            continue;
        }
        int f = dfs(nums, j);
        if (f > res) {
            res = f;
            from_[i] = j;
        }
    }
    res++;
    return res;
}

vector<int> largestDivisibleSubset(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    memo.resize(n);
    from_.resize(n, -1);
    int max_f = 0, max_i = 0;
    for (int i = 0; i < n; i++) {
        int f = dfs(nums, i);
        if (f > max_f) {
            max_f = f;
            max_i = i;
        }
    }
    vector<int> path;
    for (int i = max_i; i >= 0; i = from_[i]) {
        path.push_back(nums[i]);
    }
    return path;
}