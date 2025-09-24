#include "bits/stdc++.h"

using namespace std;

int search(vector<int> &nums, int target) {
    int lef = 0, rig = nums.size() - 1, n = nums.size();
    while (lef <= rig) {
        int mid = (lef + rig) >> 1;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[0] <= nums[mid]) {
            if (nums[0] <= target && target < nums[mid]) {
                rig = mid - 1;
            } else {
                lef = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[n - 1]) {
                lef = mid + 1;
            } else {
                rig = mid - 1;
            }
        }
    }
    return -1;
}