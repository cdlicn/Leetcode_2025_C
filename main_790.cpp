#include "bits/stdc++.h"

using namespace std;

int numTilings(int n) {
    const int MOD = 1e9 + 7;
    if (n == 1) {
        return 1;
    }
    long long pre1 = 2, pre2 = 1, pre3 = 1;
    for (int i = 3; i <= n; ++i) {
        int tmp = (pre1 * 2 + pre3) % MOD;
        pre3 = pre2;
        pre2 = pre1;
        pre1 = tmp;
    }
    return pre1;
}