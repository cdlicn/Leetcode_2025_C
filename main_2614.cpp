#include "bits/stdc++.h"

using namespace std;

int f(int v) {
    if (v <= 1) {
        return -1;
    }
    for (int i = 2; i <= sqrt(v); i++) {
        if (v % i == 0) {
            return -1;
        }
    }
    return v;
}

int diagonalPrime(vector<vector<int>> &nums) {
    int res = 0, n = nums.size();
    for (int i = 0; i < n; ++i) {
        res = max({res, f(nums[i][i]), f(nums[i][n - i - 1])});
    }
    return res;
}