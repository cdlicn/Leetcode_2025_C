#include "bits/stdc++.h"

using namespace std;

// TODO 3495. 使数组元素都变为零的最少操作次数
long long f(int n) {
    long long res = 0;
    int m = bit_width((uint64_t) n);
    for (int i = 1; i < m; ++i) {
        res += 1LL * (i + 1) / (2 << (i - 1));
    }
    return res + ((m + 1) / 2) * (n + 1 - (1 << (m - 1)));
}

long long minOperations(vector <vector<int>> &queries) {
    long long res = 0;
    for (const auto &query: queries) {
        int a = query[0], b = query[1];
        res += f(b) - f(a - 1);
    }
    return res;
}