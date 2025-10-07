#include "bits/stdc++.h"

using namespace std;

vector<int> avoidFlood(vector<int> &rains) {
    unordered_map<int, int> mp;
    set<int> st;
    vector<int> res(rains.size(), -1);
    for (int i = 0; i < rains.size(); i++) {
        if (rains[i] == 0) {
            st.emplace(i);
            res[i] = 1;
        } else {
            int x = rains[i];
            if (mp.contains(x)) {
                auto idx = st.upper_bound(mp[x]);
                if (idx == st.end()) {
                    return {};
                }
                res[*idx] = x;
                st.erase(idx);
            }
            mp[x] = i;
        }
    }
    return res;
}