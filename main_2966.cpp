#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> divideArray(vector<int> &nums, int k) {
    ranges::sort(nums);
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = 2; i < n; i += 3) {
        if (nums[i] - nums[i - 2] > k) {
            return {};
        }
        res.push_back({nums[i - 2], nums[i - 1], nums[i]});
    }
    return res;
}