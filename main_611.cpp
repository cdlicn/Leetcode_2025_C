#include "bits/stdc++.h"

using namespace std;

int triangleNumber(vector<int> &nums) {
    int res = 0, n = nums.size();
    ranges::sort(nums);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n && nums[i] + nums[j] > nums[k]; k++) {
                res++;
            }
        }
    }
    return res;
}