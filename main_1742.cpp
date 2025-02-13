#include "bits/stdc++.h"

using namespace std;

int f(int v) {
    int r = 0;
    while (v) {
        r += v % 10;
        v /= 10;
    }
    return r;
}

int countBalls(int lowLimit, int highLimit) {
    unordered_map<int, int> mp;
    int res = 0;
    for (int i = lowLimit; i <= highLimit; ++i) {
        int v = f(i);
        mp[v]++;
        res = max(res, mp[v]);
    }
    return res;
}