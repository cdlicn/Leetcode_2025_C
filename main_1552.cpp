#include "bits/stdc++.h"

using namespace std;

bool check(vector<int> &position, int m, int v) {
    int n = 1;
    int s = position[0];
    for (int i = 1; i < position.size(); ++i) {
        if (position[i] - s >= v) {
            n++;
            s = position[i];
        }
    }
    return n >= m;
}

int maxDistance(vector<int> &position, int m) {
    sort(position.begin(), position.end());
    int left = 0;
    int right = (position.back() - position[0]) / (m - 1) + 1;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        (check(position, m, mid) ? left : right) = mid;
    }
    return left;
}