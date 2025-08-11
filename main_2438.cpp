#include "bits/stdc++.h"

using namespace std;

vector<int> productQueries(int n, vector<vector<int>> &queries) {
    const int MOD = 1'000'000'007;
    vector<int> powers;
    while (n) {
        int lowbit = n & -n;
        powers.push_back(lowbit);
        n ^= lowbit;
    }

    vector<int> res;
    for (auto &q: queries) {
        long long mul = 1;
        for (int j = q[0]; j <= q[1]; j++) {
            mul = mul * powers[j] % MOD;
        }
        res.push_back(mul);
    }
    return res;
}