#include "bits/stdc++.h"

using namespace std;

// TODO 2411. 按位或最大的最小子数组长度
vector<int> smallestSubarrays(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) { // 计算右端点为 i 的子数组的或值
        int x = nums[i];
        ans[i] = 1; // 子数组的长度至少是 1
        // 循环直到 nums[j] 无法增大，其左侧元素也无法增大
        for (int j = i - 1; j >= 0 && (nums[j] | x) != nums[j]; j--) {
            nums[j] |= x; // nums[j] 增大，现在 nums[j] = 原数组 nums[j] 到 nums[i] 的或值
            ans[j] = i - j + 1; // nums[j] 最后一次增大时的子数组长度就是答案
        }
    }
    return ans;
}