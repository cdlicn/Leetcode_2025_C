#include "bits/stdc++.h"

using namespace std;

int minimumOperations(vector<int> &nums) {
    unordered_set<int> st;
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (st.count(nums[i])) {
            return i / 3 + 1;
        }
        st.insert(nums[i]);
    }
    return 0;
}