#include "bits/stdc++.h"

using namespace std;

long long minTime(vector<int> &skill, vector<int> &mana) {
    int n = skill.size();
    vector<long long> res(n + 1);
    for (const auto &m: mana) {
        for (int i = 1; i <= n; ++i) {
            long long x = skill[i - 1] * m;
            res[i] = max(res[i], res[i - 1]) + x;
        }
        for (int i = n - 1; i > 0; i--) {
            long long x = skill[i] * m;
            res[i] = res[i + 1] - x;
        }
    }
    return res[n];
}