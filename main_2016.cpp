#include "bits/stdc++.h"

using namespace std;

int maximumDifference(vector<int> &nums) {
    int n = nums.size();
    vector<int> lmin(n, INT_MAX), rmax(n, 0);
    lmin[0] = nums[0];
    rmax[n - 1] = nums[n - 1];
    for (int i = 1; i < n; ++i) {
        lmin[i] = min(lmin[i - 1], nums[i]);
        rmax[n - i - 1] = max(rmax[n - i], nums[n - i - 1]);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = max(res, rmax[i] - lmin[i]);
    }
    return res == 0 ? -1 : res;
}