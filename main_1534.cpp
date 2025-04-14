#include "bits/stdc++.h"

using namespace std;

int countGoodTriplets(vector<int> &arr, int a, int b, int c) {
    int n = arr.size(), mx = ranges::max(arr), res = 0;
    vector<int> pre(mx + 2);
    for (int i = 0; i < n; ++i) {
        int x = arr[i];
        for (int j = i + 1; j < n; ++j) {
            int y = arr[j];
            if (abs(x - y) > b) {
                continue;
            }
            int lef = max({x - a, y - c, 0});
            int rig = min({x + a, y + c, mx});
            res += max(pre[rig + 1] - pre[lef], 0);
        }
        for (int j = x + 1; j < mx + 2; ++j) {
            pre[j]++;
        }
    }
    return res;
}