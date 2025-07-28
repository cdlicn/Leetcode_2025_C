#include "bits/stdc++.h"

using namespace std;

int countMaxOrSubsets(vector<int> &nums) {
    int mx = 0;
    for (const auto &num: nums){
        mx |= num;
    }
    int res = 0;

    auto dfs = [&](this auto &&dfs, int i, int subset_or) -> void {
        if (i == nums.size()) {
            if (subset_or == mx) {
                res++;
            }
            return;
        }
        dfs(i + 1, subset_or);
        dfs(i + 1, subset_or | nums[i]);
    };

    dfs(0, 0);
    return res;
}