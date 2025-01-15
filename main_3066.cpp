#include "bits/stdc++.h"

using namespace std;

int minOperations(vector<int> &nums, int k) {
    priority_queue<long long, vector<long long>, greater<>> pq;
    for (const auto &num: nums) {
        pq.emplace(num);
    }
    int res = 0;
    while (pq.top() < k) {
        long long x = pq.top();
        pq.pop();
        long long y = pq.top();
        pq.pop();
        pq.emplace(x * 2 + y);
        res++;
    }
    return res;
}