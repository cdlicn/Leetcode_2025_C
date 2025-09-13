#include "bits/stdc++.h"

using namespace std;

int maxFreqSum(string s) {
    vector<int> cnt(26, 0);
    int a = 0, b = 0;
    for (const auto &c: s) {
        int i = c - 'a';
        cnt[i]++;
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            a = max(a, cnt[i]);
        } else {
            b = max(b, cnt[i]);
        }
    }
    return a + b;
}