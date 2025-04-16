#include "bits/stdc++.h"

using namespace std;

long long countGood(vector<int> &nums, int k) {
    long long res = 0;
    unordered_map<int, int> mp;
    int n = 0, lef = 0;
    for (const auto &num: nums) {
        n += mp[num];
        mp[num]++;
        while (n >= k) {
            mp[nums[lef]]--;
            n -= mp[nums[lef]];
            lef++;
        }
        res += lef;
    }
    return res;
}