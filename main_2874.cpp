#include "bits/stdc++.h"

using namespace std;

long long maximumTripletValue(vector<int> &nums) {
    long long res = 0;
    int mmx = 0, mx = 0;
    for (int x: nums) {
        res = max(res, 1LL * mmx * x);
        mmx = max(mmx, mx - x);
        mx = max(mx, x);
    }
    return res;
}