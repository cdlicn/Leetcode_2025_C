#include "bits/stdc++.h"

using namespace std;

int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime) {
    int n = startTime.size();

    auto val = [&](int i) -> int {
        if (i == 0) {
            return startTime[0];
        } else if (i == n) {
            return eventTime - endTime[n - 1];
        } else {
            return startTime[i] - endTime[i - 1];
        }
    };

    int a = -1, b = -1, c = -1;
    for (int i = 0; i <= n; ++i) {
        int v = val(i);
        if (a < 0 || v > val(a)) {
            c = b;
            b = a;
            a = i;
        } else if (b < 0 || v > val(b)) {
            c = b;
            b = i;
        } else if (c < 0 || v > val(c)) {
            c = i;
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        int v = endTime[i] - startTime[i];
        if ((i != a && i + 1 != a && v <= val(a)) || (i != b && i + 1 != b && v <= val(b)) || v <= val(c)) {
            res = max(res, val(i) + val(i + 1) + v);
        } else {
            res = max(res, val(i) + val(i + 1));
        }
    }
    return res;
}