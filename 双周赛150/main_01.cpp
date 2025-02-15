#include "bits/stdc++.h"

using namespace std;

int sumOfGoodNumbers(vector<int> &nums, int k) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
        bool b = true;
        if (i - k >= 0 && nums[i] <= nums[i - k]) {
            b = false;
        }
        if (i + k < nums.size() && nums[i] <= nums[i + k]) {
            b = false;
        }
        if (b) {
            res += nums[i];
        }
    }
    return res;
}