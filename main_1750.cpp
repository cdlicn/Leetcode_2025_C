#include "bits/stdc++.h"

using namespace std;


// TODO 1751. 最多可以参加的会议数目 II
int maxValue(vector<vector<int>> &events, int k) {
    // 特判 k=1 的情况可以更快
    if (k == 1) {
        return ranges::max(events, {}, [](auto &e) { return e[2]; })[2];
    }

    ranges::sort(events, {}, [](auto &e) { return e[1]; }); // 按照结束时间排序
    int n = events.size();
    vector f(n + 1, vector<int>(k + 1));
    for (int i = 0; i < n; i++) {
        int p = lower_bound(events.begin(), events.begin() + i, events[i][0],
                            [](auto &e, int lower) { return e[1] < lower; }) - events.begin();
        for (int j = 1; j <= k; j++) {
            // 为什么是 p 不是 p+1：上面算的是 >= startDay，-1 后得到 < startDay，但由于还要 +1，抵消了
            f[i + 1][j] = max(f[i][j], f[p][j - 1] + events[i][2]);
        }
    }
    return f[n][k];
}