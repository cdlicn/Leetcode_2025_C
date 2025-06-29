#include "bits/stdc++.h"

using namespace std;

const int MOD = 1'000'000'007;
const int MX = 100'000;

int pow2[MX];

auto init = [] {
    pow2[0] = 1;
    for (int i = 1; i < MX; i++) {
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }
    return 0;
}();

int numSubseq(vector<int> &nums, int target) {
    long long res = 0;
    ranges::sort(nums);
    int lef = 0, rig = nums.size() - 1;
    while (lef <= rig) {
        if (nums[lef] + nums[rig] <= target) {
            res += pow2[rig - lef];
            lef++;
        } else {
            rig--;
        }
    }
    return res % MOD;
}