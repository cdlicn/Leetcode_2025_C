#include "bits/stdc++.h"

using namespace std;

int largestPerimeter(vector<int> &nums) {
    ranges::sort(nums);
    for (int i = nums.size() - 1; i >= 2; i--) {
        if (nums[i] > nums[i - 1] + nums[i - 2]) {
            return nums[i] + nums[i - 1] + nums[i - 2];
        }
    }
    return 0;
}