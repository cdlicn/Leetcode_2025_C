#include "bits/stdc++.h"

using namespace std;

int areaOfMaxDiagonal(vector<vector<int>> &d) {
    int idx = 0;
    for (int i = 1; i < d.size(); ++i) {
        int a = d[i][0] * d[i][0] + d[i][1] * d[i][1], b = d[idx][0] * d[idx][0] + d[idx][1] * d[idx][1];
        if ((a > b) || (a == b && d[i][0] * d[i][1] > d[idx][0] * d[idx][1])) {
            idx = i;
        }
    }
    return d[idx][0] * d[idx][1];
}