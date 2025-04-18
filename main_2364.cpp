#include "bits/stdc++.h"

using namespace std;

long long countBadPairs(vector<int> &nums) {
    int n = nums.size();
    long long res = 1L * n * (n - 1) / 2;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int s = nums[i] - i;
        res -= mp[s];
        mp[s]++;
    }
    return res;
}