#include "bits/stdc++.h"

using namespace std;

// TODO 2588. 统计美丽子数组数目
long long beautifulSubarrays(vector<int> &nums) {
    long long res = 0;
    int s = 0;
    unordered_map<int, int> cnt{{0, 1}};
    for (int x: nums) {
        s ^= x;
        res += cnt[s]++;
    }
    return res;
}