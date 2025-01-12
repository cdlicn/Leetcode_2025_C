#include "bits/stdc++.h"

using namespace std;

int largestCombination(vector<int> &candidates) {
    int res = 0;
    int mx = 0;
    for (const auto &c: candidates) {
        mx = max(mx, c);
    }
    for (int i = 0; 1 << i <= mx; i++) {
        int tmp = 0;
        for (const auto &c: candidates) {
            tmp += c >> i & 1;
        }
        res = max(res, tmp);
    }
    return res;
}