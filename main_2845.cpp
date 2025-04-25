#include "bits/stdc++.h"

using namespace std;

long long countInterestingSubarrays(vector<int> &nums, int modulo, int k) {
    long long res = 0;
    int n = nums.size();
    vector<int> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + (nums[i] % modulo == k);
    }
    vector<int> cnt(min(n + 1, modulo));
    for (int s: pre) {
        if (s >= k) {
            res += cnt[(s - k) % modulo];
        }
        cnt[s % modulo]++;
    }
    return res;
}