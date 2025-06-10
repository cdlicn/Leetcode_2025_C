#include "bits/stdc++.h"

using namespace std;

int maxDifference(string s) {
    vector<int> cnt(26, 0);
    for (const auto &c: s) {
        cnt[c - 'a']++;
    }
    int a1 = 0, a2 = s.size();
    for (const auto &a: cnt) {
        if (a % 2) {
            a1 = max(a1, a);
        } else if (a) {
            a2 = min(a2, a);
        }
    }
    return a1 - a2;
}