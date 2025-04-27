#include "bits/stdc++.h"

using namespace std;

int countSubarrays(vector<int> &nums) {
    int res = 0;
    for (int i = 1; i < nums.size() - 1; ++i) {
        if (2 * (nums[i - 1] + nums[i + 1]) == nums[i]) {
            res++;
        }
    }
    return res;
}