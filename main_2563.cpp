#include "bits/stdc++.h"

using namespace std;

long long countFairPairs(vector<int> &nums, int lower, int upper) {
    long long res = 0;
    ranges::sort(nums);
    for (int i = 0; i < nums.size(); ++i) {
        auto r = upper_bound(nums.begin(), nums.begin() + i, upper - nums[i]);
        auto l = lower_bound(nums.begin(), nums.begin() + i, lower - nums[i]);
        res += r - l;
    }
    return res;
}