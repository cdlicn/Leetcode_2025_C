#include "bits/stdc++.h"

using namespace std;

int maxIncreasingSubarrays(vector<int> &nums) {
    int res = 0, pre_cnt = 0, cnt = 1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] <= nums[i - 1]) {
            res = max({res, cnt / 2, min(pre_cnt, cnt)});
            pre_cnt = cnt;
            cnt = 0;
        }
        cnt++;
    }
    return res;
}