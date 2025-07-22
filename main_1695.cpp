#include "bits/stdc++.h"

using namespace std;

int maximumUniqueSubarray(vector<int> &nums) {
    int lef = 0, rig = 1, res = 0, n = nums.size(), sum = nums[0];
    set<int> st;
    st.emplace(nums[0]);
    while (rig < n) {
        int x = nums[rig];
        while (st.contains(x)) {
            sum -= nums[lef];
            st.erase(nums[lef]);
            lef++;
        }
        st.emplace(x);
        sum += x;
        rig++;
        res = max(res, sum);
    }
    return res;
}