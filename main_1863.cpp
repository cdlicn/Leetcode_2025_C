#include "bits/stdc++.h"

using namespace std;

int subsetXORSum(vector<int> &nums) {
    int or_ = 0;
    for (int x: nums) {
        or_ |= x;
    }
    return or_ << (nums.size() - 1);
}