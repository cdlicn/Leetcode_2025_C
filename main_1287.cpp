#include "bits/stdc++.h"

using namespace std;

int findSpecialInteger(vector<int> &arr) {
    int n = arr.size();
    int pre = -1, cnt = 0;
    for (const auto &a: arr) {
        if (pre != a) {
            cnt = 1;
            pre = a;
        } else {
            cnt++;
        }
        if (cnt > n / 4) {
            return a;
        }
    }
    return -1;
}