#include "bits/stdc++.h"

using namespace std;

vector<int> findKDistantIndices(vector<int> &nums, int key, int k) {
    int n = nums.size();
    vector<int> res;
    for (int i = 0, j = 0; i < n; ++i) {
        if (nums[i] == key) {
            j = max(j, i - k);
            while (j < n && j <= i + k) {
                res.emplace_back(j++);
            }
        }
    }
    return res;
}