#include "bits/stdc++.h"

using namespace std;

string robotWithString(string s) {
    int n = s.size();
    vector<char> v(n + 1);
    v[n] = 'z';
    for (int i = n - 1; i >= 0; i--) {
        v[i] = min(v[i + 1], s[i]);
    }
    stack<int> st;
    string res = "";
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        st.push(c);
        while (!st.empty() && st.top() <= v[i + 1]) {
            res += st.top();
            st.pop();
        }
    }
    return res;
}