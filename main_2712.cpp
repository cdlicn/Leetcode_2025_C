#include "bits/stdc++.h"

using namespace std;

long long minimumCost(string s) {
    int n = s.size();
    long long res = 0;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] != s[i]) {
            res += min(i, n - i);
        }
    }
    return res;
}