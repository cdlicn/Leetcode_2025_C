#include "bits/stdc++.h"

using namespace std;

int waysToSplitArray(vector<int> &nums) {
    int res = 0;
    long long sum = 0;
    for (const auto &num: nums) {
        sum += num;
    }
    long long lefSum = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
        int num = nums[i];
        lefSum += num;
        sum -= num;
        if (lefSum >= sum) {
            res++;
        }
    }
    return res;
}