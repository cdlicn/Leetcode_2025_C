#include "bits/stdc++.h"

using namespace std;

long long minimumDifference(vector<int> &nums) {
    int m = nums.size();
    int n = m / 3;

    priority_queue<int, vector<int>, greater<>> mn_pq(nums.end() - n, nums.end());
    long long sum = reduce(nums.end() - n, nums.end(), 0LL);

    vector<long long> suf_max(m - n + 1);
    suf_max[m - n] = sum;

    for (int i = m - n - 1; i >= n; i--) {
        if (nums[i] > mn_pq.top()) {
            sum = sum - mn_pq.top() + nums[i];
            mn_pq.pop();
            mn_pq.emplace(nums[i]);
        }
        suf_max[i] = sum;
    }

    priority_queue<int> mx_pq(nums.begin(), nums.begin() + n);
    sum = reduce(nums.begin(), nums.begin() + n, 0LL);

    long long res = sum - suf_max[n];
    for (int i = n; i < m - n; i++) {
        if (nums[i] < mx_pq.top()) {
            sum += nums[i] - mx_pq.top();
            mx_pq.pop();
            mx_pq.emplace(nums[i]);
        }
        res = min(res, sum - suf_max[i + 1]);
    }
    return res;
}
