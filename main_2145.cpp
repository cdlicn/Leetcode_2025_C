#include "bits/stdc++.h"

using namespace std;

int numberOfArrays(vector<int> &differences, int lower, int upper) {
    long long mn = 0, mx = 0, sum = 0;
    for (const auto &d: differences) {
        sum += d;
        mn = min(sum, mn);
        mx = max(sum, mx);
    }
    return max(upper - lower - mx + mn + 1, 0LL);
}