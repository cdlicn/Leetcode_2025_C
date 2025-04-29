#include "bits/stdc++.h"

using namespace std;

long long countSubarrays(vector<int> &nums, int k) {
    long long res = 0;
    int mx = ranges::max(nums);
    int n = 0, lef = 0;
    for (int i = 0; i < nums.size(); ++i) {
        n += nums[i] == mx;
        while (n == k) {
            n -= nums[lef] == mx;
            lef++;
        }
        res += lef;
    }
    return res;
}