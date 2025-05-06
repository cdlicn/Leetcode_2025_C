#include "bits/stdc++.h"

using namespace std;

vector<int> buildArray(vector<int>& nums) {
    vector<int> res;
    for (const auto &num: nums){
        res.emplace_back(nums[num]);
    }
    return res;
}