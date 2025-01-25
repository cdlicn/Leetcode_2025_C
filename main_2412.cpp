#include "bits/stdc++.h"

using namespace std;

long long minimumMoney(vector<vector<int>> &transactions) {
    long long totalLose = 0;
    int mx = 0;
    for (const auto &t: transactions) {
        totalLose += max(t[0] - t[1], 0);
        mx = max(mx, min(t[0], t[1]));
    }
    return totalLose + mx;
}