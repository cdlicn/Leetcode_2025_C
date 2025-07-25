#include "bits/stdc++.h"

using namespace std;

int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime) {
    int res = 0;
    int n = startTime.size();
    vector<int> free(n + 1);
    free[0] = startTime[0];
    for (int i = 1; i < n; ++i) {
        free[i] = startTime[i] - endTime[i - 1];
    }
    free[n] = eventTime - endTime[n - 1];
    int s = 0;
    for (int i = 0; i <= n; ++i) {
        s += free[i];
        if (i < k) {
            continue;
        }
        res = max(res, s);
        s -= free[i - k];
    }
    return res;
}