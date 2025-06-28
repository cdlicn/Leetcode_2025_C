#include "bits/stdc++.h"

using namespace std;

vector<int> maxSubsequence(vector<int> &nums, int k) {
    vector<int> idx(nums.size());
    ranges::iota(idx, 0);
    ranges::sort(idx, {}, [&](int i) { return -nums[i]; });

    idx.resize(k);
    ranges::sort(idx);

    for (int &i: idx) {
        i = nums[i];
    }
    return idx;
}