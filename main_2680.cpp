#include "bits/stdc++.h"

using namespace std;

long long maximumOr(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> pre(n);
    for (int i = 1; i < n; ++i) {
        pre[i] = pre[i - 1] | nums[i - 1];
    }
    long long res = 0;
    int suf = 0;
    for (int i = n - 1; i >= 0; i--) {
        res = max(res, pre[i] | ((long long) nums[i] << k) | suf);
        suf |= nums[i];
    }
    return res;
}