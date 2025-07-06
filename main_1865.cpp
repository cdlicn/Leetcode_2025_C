#include "bits/stdc++.h"

using namespace std;

class FindSumPairs {
public:
    vector<int> nums;
    unordered_map<int, int> mp1, mp2;

    FindSumPairs(vector<int> &nums1, vector<int> &nums2) {
        nums = nums2;
        for (const auto &n: nums1) {
            mp1[n]++;
        }
        for (const auto &n: nums2) {
            mp2[n]++;
        }
    }

    void add(int index, int val) {
        int v = nums[index];
        mp2[v]--;
        nums[index] += val;
        mp2[nums[index]]++;
    }

    int count(int tot) {
        int res = 0;
        for (const auto &[k, v]: mp1) {
            res += mp2.contains(tot - k) ? v * mp2[tot - k] : 0;
        }
        return res;
    }
};