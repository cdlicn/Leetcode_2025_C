#include "bits/stdc++.h"

using namespace std;

int countCompleteSubarrays(vector<int> &nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    int l = st.size();
    unordered_map<int, int> mp;
    int res = 0, lef = 0;
    for (const auto &num: nums) {
        mp[num]++;
        while (mp.size() == l) {
            int x = nums[lef++];
            mp[x]--;
            if (mp[x] == 0) {
                mp.erase(x);
            }
        }
        res += lef;

    }
    return res;
}