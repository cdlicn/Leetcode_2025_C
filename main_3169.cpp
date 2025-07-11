#include "bits/stdc++.h"

using namespace std;

int countDays(int days, vector<vector<int>> &meetings) {
    int n = meetings.size();
    sort(meetings.begin(), meetings.end());

    int res = meetings[0][0] - 1;
    int bef = meetings[0][1];

    for (int i = 1; i < n; i++) {
        res += meetings[i][0] > bef ? meetings[i][0] - bef - 1 : 0;
        bef = max(bef, meetings[i][1]);
    }
    res += days - bef;
    return res;
}