#include "bits/stdc++.h"

using namespace std;

long long distributeCandies(int n, int limit) {
    long long res = 0;
    for (int i = max(0, n - 2 * limit); i <= min(n, limit); ++i) {
        res += min(n - i, limit) - max(0, n - i - limit) + 1;
    }
    return res;
}