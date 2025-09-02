#include "bits/stdc++.h"

using namespace std;

static bool cmp(vector<int> a, vector<int> b) {
    if (a[0] < b[0]) {
        return true;
    }
    if (a[0] > b[0]) {
        return false;
    }
    return a[1] > b[1];
}

int numberOfPairs(vector<vector<int>> &points) {
    sort(points.begin(), points.end(), cmp);
    for (const auto &item: points) {
        cout << item[0] << " " << item[1] << endl;
    }

    int res = 0, n = points.size();
    for (int i = 0; i < n; ++i) {
        int y = points[i][1], max_y = INT_MIN;
        for (int j = i + 1; j < n && max_y <= y; ++j) {
            if (points[j][1] <= y && points[j][1] > max_y) {
                max_y = points[j][1];
                res++;
            }
        }
    }
    return res;
}