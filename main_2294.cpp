#include "bits/stdc++.h"

using namespace std;

int partitionArray(vector<int> &nums, int k) {
    ranges::sort(nums);
    int v = nums[0];
    int res = 1;
    for (const auto &num: nums) {
        if (num - v > k) {
            res++;
            v = num;
        }
    }
    return res;
}