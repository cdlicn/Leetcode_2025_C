#include "bits/stdc++.h"

using namespace std;

string clearStars(string s) {
    stack<int> stks[26];
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*') {
            for (auto &st: stks) {
                if (!st.empty()) {
                    st.pop();
                    break;
                }
            }
        } else {
            stks[s[i] - 'a'].emplace(i);
        }
    }

    vector<int> idx;
    for (auto &stk: stks) {
        while (!stk.empty()){
            idx.emplace_back(stk.top());
            stk.pop();
        }
    }
    ranges::sort(idx);

    string res(idx.size(), 0);
    for (int i = 0; i < idx.size(); i++) {
        res[i] = s[idx[i]];
    }
    return res;
}