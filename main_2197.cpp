#include "bits/stdc++.h"

using namespace std;

vector<int> replaceNonCoprimes(vector<int> &nums) {
    vector<int> stk;
    for (auto &num: nums) {
        while (!stk.empty() && gcd(stk.back(), num) > 1) {
            num = lcm(num, stk.back());
            stk.pop_back();
        }
        stk.emplace_back(num);
    }
    return stk;
}