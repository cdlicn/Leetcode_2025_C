#include "bits/stdc++.h"

using namespace std;

int longestSubarray(vector<int> &nums) {
    int cnt0 = 0;
    int cnt1 = 0;
    int lef = 0;
    int res = 0;
    for (int rig = 0; rig < nums.size(); ++rig) {
        nums[rig] == 0 ? cnt0++ : cnt1++;
        while (cnt0 > 1) {
            nums[lef] == 0 ? cnt0-- : cnt1--;
            lef++;
        }
        res = max(res, rig - lef);
    }
    return res;
}