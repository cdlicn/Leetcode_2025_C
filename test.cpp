#include "bits/stdc++.h"

using namespace std;

int longestSubsequence(vector<int> &nums) {
    int n = nums.size();
    // v[i] map 下标i的数字和下标j的数字的差为key，子序列最长为value
    vector<map<int, int>> vm(n);
    int res = 2;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int c = abs(nums[i] - nums[j]);
            vm[i][c] = 2;
            for (const auto &[k, v]: vm[j]) {
                if (k >= c) {
                    vm[i][c] = max(vm[i][c], v + 1);
                    res = max(res, vm[i][c]);
                }
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums = {5, 8, 9, 8, 6, 1, 7, 4, 7};
    cout << longestSubsequence(nums);
}

// [5,8,9,8,6,1,7,4,7] 6
//