#include "bits/stdc++.h"

using namespace std;

bool hasIncreasingSubarrays(vector<int> &nums, int k) {
    int n = nums.size();
    int cnt = 1, pre_cnt = 0, res = 0;
    for (int i = 1; i < n; ++i) {
        if (nums[i] > nums[i - 1]) {
            ++cnt;
        } else {
            pre_cnt = cnt;
            cnt = 1;
        }
        res = max(res, min(pre_cnt, cnt));
        res = max(res, cnt / 2);
    }
    return res >= k;
}