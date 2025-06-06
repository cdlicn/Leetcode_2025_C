#include "bits/stdc++.h"

using namespace std;

int candy(vector<int> &ratings) {
    int n = ratings.size();
    vector<int> lef(n, 1), rig(n, 1);
    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            lef[i] = lef[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            rig[i] = rig[i + 1] + 1;
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += max(lef[i], rig[i]);
    }
    return res;
}