#include "bits/stdc++.h"

using namespace std;

int findNumbers(vector<int> &nums) {
    int res = 0;
    for (const auto &num: nums) {
        res += (to_string(num).size() + 1) % 2;
    }
    return res;
}