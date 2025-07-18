#include "bits/stdc++.h"

using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<>> pq;
    int k;

    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        for (const auto &n: nums) {
            add(n);
        }
    }

    int add(int val) {
        pq.emplace(val);
        if (pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
};