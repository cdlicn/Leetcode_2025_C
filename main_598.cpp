#include "bits/stdc++.h"

using namespace std;

int maxCount(int m, int n, vector<vector<int>> &ops) {
    int minM = m;
    int minN = n;
    for (const auto &op: ops) {
        minM = min(minM, op[0]);
        minN = min(minN, op[1]);
    }
    return minM * minN;
}