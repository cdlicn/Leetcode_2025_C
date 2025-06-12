#include "bits/stdc++.h"

using namespace std;

int maxAdjacentDistance(vector<int> &nums) {
    int n = nums.size(), res = abs(nums[0] - nums[n - 1]);
    for (int i = 1; i < n; ++i) {
        res = max(abs(nums[i] - nums[i - 1]), res);
    }
    return res;
}