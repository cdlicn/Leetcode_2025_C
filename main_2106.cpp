#include "bits/stdc++.h"

using namespace std;

int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k) {
    int lef = ranges::lower_bound(fruits, startPos - k, {}, [](auto &f) { return f[0]; }) - fruits.begin();
    int s = 0, rig = lef, n = fruits.size();
    while (rig < n && fruits[rig][0] <= startPos) {
        s += fruits[rig][1];
        rig++;
    }

    int res = s;
    while (rig < n && fruits[rig][0] <= startPos + k) {
        s += fruits[rig][1];
        while (fruits[rig][0] * 2 - fruits[lef][0] - startPos > k &&
               fruits[rig][0] - fruits[lef][0] * 2 + startPos > k) {
            s -= fruits[lef][1];
            lef++;
        }
        res = max(res, s);
        rig++;
    }
    return res;
}