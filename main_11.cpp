#include "bits/stdc++.h"

using namespace std;

int maxArea(vector<int> &height) {
    int res = 0, lef = 0, rig = height.size() - 1;
    while (lef < rig) {
        res = max(res, (rig - lef) * min(height[lef], height[rig]));
        if (height[lef] > height[rig]) {
            rig--;
        } else {
            lef++;
        }
    }
    return res;
}