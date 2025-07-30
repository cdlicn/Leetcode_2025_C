#include "bits/stdc++.h"

using namespace std;

int longestSubarray(vector<int> &nums) {
    int mx = ranges::max(nums);
    int n = 0, res = 0;
    for (const auto &num: nums) {
        if (num == mx) {
            n++;
            res = max(res, n);
        } else {
            n = 0;
        }
    }
    return max(res, n);
}