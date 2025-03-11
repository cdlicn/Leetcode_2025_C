#include "bits/stdc++.h"

using namespace std;

int sumOfBeauties(vector<int> &nums) {
    int res = 0;
    int n = nums.size();
    vector<int> pre_mx(n, 0), aft_mn(n, INT_MAX);
    for (int i = 1; i < n - 1; i++) {
        pre_mx[i] = max(pre_mx[i - 1], nums[i - 1]);
        aft_mn[n - i - 1] = min(aft_mn[n - i], nums[n - i]);
    }
    for (int i = 1; i < n - 1; i++) {
        if (nums[i] > pre_mx[i] && aft_mn[i] > nums[i]) {
            res += 2;
        } else if (nums[i] > nums[i - 1] && nums[i + 1] > nums[i]) {
            res += 1;
        }
    }
    return res;
}