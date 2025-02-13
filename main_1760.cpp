#include "bits/stdc++.h"

using namespace std;

int minimumSize(vector<int> &nums, int maxOperations) {
    auto check = [&](int m) -> bool {
        long long cnt = 0;
        for (int x: nums) {
            cnt += (x - 1) / m;
        }
        return cnt <= maxOperations;
    };

    int left = 0; // 循环不变量 check(left) == false
    int right = ranges::max(nums); // 循环不变量 check(right) == true
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        (check(mid) ? right : left) = mid;
    }
    return right;
}