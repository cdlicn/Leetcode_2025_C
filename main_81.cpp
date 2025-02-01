#include "bits/stdc++.h"

using namespace std;

bool check(vector<int> &nums, int i, int lef, int rig, int target) {
    if (nums[i] > nums[rig]) {
        return target > nums[rig] && nums[i] >= target;
    }
    return target > nums[rig] || nums[i] >= target;
}

bool search(vector<int> &nums, int target) {
    int lef = -1, rig = nums.size() - 1;
    while (lef + 1 < rig) {
        int mid = lef + (rig - lef) / 2;
        if (nums[mid] == nums[rig]) {
            rig--;
        } else if (check(nums, mid, lef, rig, target)) {
            rig = mid;
        } else {
            lef = mid;
        }
    }
    return nums[rig] == target;
}