#include "bits/stdc++.h"

using namespace std;

int f(vector<int> &v1, vector<int> &v2) {
    int top = 0, bottom = 0;
    for (int i = 0; i < v1.size(); i++) {
        int x = v1[i], y = v2[i], target = v1[0];
        if (x != target && y != target) {
            return INT_MAX;
        }
        if (x != target) {
            top++;
        } else if (y != target) {
            bottom++;
        }
    }
    return min(top, bottom);
}

int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
    int res = min(f(tops, bottoms), f(bottoms, tops));
    return res == INT_MAX ? -1 : res;
}