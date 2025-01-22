#include "bits/stdc++.h"

using namespace std;

int maxCoins(vector<int> &piles) {
    int res = 0;
    sort(piles.begin(), piles.end());
    int n = piles.size();
    for (int i = 1; i <= n / 3; ++i) {
        res += piles[n - 2 * i];
    }
    return res;
}