#include "bits/stdc++.h"

using namespace std;

int longestSubsequence(string s, int k) {
    int n = s.length();
    int m = bit_width((uint32_t) k);
    if (n < m) {
        return n;
    }
    int suf_val = stoi(s.substr(n - m), nullptr, 2);
    int res = suf_val <= k ? m : m - 1;
    for (int i = 0; i < n - m; ++i) {
        res += s[i] == '0';
    }
    return res;
}