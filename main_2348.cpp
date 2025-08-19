#include "bits/stdc++.h"

using namespace std;

long long zeroFilledSubarray(vector<int> &nums) {
    long long res = 0;
    int n = 0;
    for (const auto &num: nums) {
        n = num == 0 ? n + 1 : 0;
        res += n;
    }
    return res;
}
