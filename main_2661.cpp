#include "bits/stdc++.h"

using namespace std;

bool check(vector<int> &nums, int mx, int p) {
    int cnt = 0;
    for (int i = 0; i + 1 < nums.size(); i++) {
        if (nums[i + 1] - nums[i] <= mx) { // 选 nums[i] 和 nums[i+1]
            cnt++;
            i++;
        }
    }
    return cnt >= p;
}

int minimizeMax(vector<int> &nums, int p) {
    sort(nums.begin(), nums.end());

    int left = -1, right = nums.back() - nums[0];
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        (check(nums, mid, p) ? right : left) = mid;
    }
    return right;
}