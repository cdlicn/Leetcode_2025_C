#include "bits/stdc++.h"

using namespace std;

int totalFruit(vector<int> &fruits) {
    int lef = 0, rig = 1, n = fruits.size();
    // 数字，最后一位的位置
    pair<int, int> a, b;

    while (rig < n && fruits[rig] == fruits[lef]) {
        a.second = rig;
        rig++;
    }

    int res = rig - lef;
    a.first = fruits[lef], b.first = fruits[rig], b.second = rig;

    while (rig < n) {
        if (fruits[rig] == a.first) {
            a.second = rig;
        } else if (fruits[rig] == b.first) {
            b.second = rig;
        } else {
            if (a.second > b.second) {
                swap(a, b);
            }
            a.first = b.first;
            b.first = fruits[rig];
            lef = a.second + 1;
            a.second = b.second;
            b.second = rig;
        }
        res = max(res, rig - lef + 1);
        rig++;
    }
    return res;
}