#include "bits/stdc++.h"

using namespace std;

int findClosestNumber(vector<int> &nums) {
    int res = INT_MAX;
    for (const auto &num: nums) {
        if (abs(num) < abs(res)) {
            res = num;
        } else if (abs(num) == abs(res)) {
            res = max(res, num);
        }
    }
    return res;
}