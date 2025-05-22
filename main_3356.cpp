#include "bits/stdc++.h"

using namespace std;

// TODO 3356. 零数组变换 II
int minZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    vector<int> diff(n + 1);
    auto check = [&](int k) -> bool {
        ranges::fill(diff, 0);
        for (int i = 0; i < k; i++) { // 前 k 个询问
            auto &q = queries[i];
            int l = q[0], r = q[1], val = q[2];
            diff[l] += val;
            diff[r + 1] -= val;
        }

        int sum_d = 0;
        for (int i = 0; i < n; i++) {
            sum_d += diff[i];
            if (nums[i] > sum_d) {
                return false;
            }
        }
        return true;
    };

    int q = queries.size();
    int left = -1, right = q + 1;
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        (check(mid) ? right : left) = mid;
    }
    return right <= q ? right : -1;
}