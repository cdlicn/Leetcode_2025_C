#include "bits/stdc++.h"

using namespace std;

int maxSum(vector<int> &nums) {
    unordered_set<int> st;
    int s = 0, mx = INT_MIN;
    for (int x: nums) {
        if (x < 0) {
            mx = max(mx, x);
        } else if (st.insert(x).second) {
            s += x;
        }
    }
    return st.empty() ? mx : s;
}