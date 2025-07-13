#include "bits/stdc++.h"

using namespace std;


char processStr(string s, long long k) {
    vector<pair<long long , char>> v;
    long long len = 0;
    for (const auto &c: s) {
        if (c == '*') {
            if (len <= 0) {
                continue;
            }
            len -= 1;
            v.emplace_back(len, c);
        } else if (c == '#') {
            if (len <= 0) {
                continue;
            }
            v.emplace_back(len, c);
            len *= 2;
        } else if (c == '%') {
            if (len <= 0) {
                continue;
            }
            v.emplace_back(len, c);
        } else {
            v.emplace_back(len, c);
            len++;
        }
    }
    if (len <= k) {
        return '.';
    }
    long long idx = k;

    for (int i = v.size() - 1; i >= 0; i--) {
        auto [v_len, c] = v[i];
        if (c == '*') {
            if(idx >= v_len) {
                idx++;
            }
        } else if (c == '#') {
            if (idx >= v_len) {
                idx -= v_len;
            }
        } else if (c == '%') {
            idx = v_len - 1 - idx;
        } else {
            if (idx == v_len) {
                return c;
            }
        }
    }
    return '.';
}