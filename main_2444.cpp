#include "bits/stdc++.h"

using namespace std;

long long countSubarrays(vector<int> &nums, int minK, int maxK) {
    int mnI = -1, mxI = -1, s = -1;
    long long res = 0;
    for (int i = 0; i < nums.size(); ++i) {
        int n = nums[i];
        if (n == minK) {
            mnI = i;
        }
        if (n == maxK) {
            mxI = i;
        }
        if (n < minK || n > maxK) {
            s = i;
        }
        res += max(min(mnI, mxI) - s, 0);
    }
    return res;
}