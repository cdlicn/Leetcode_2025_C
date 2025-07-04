#include "bits/stdc++.h"

using namespace std;

char kthCharacter(long long k, vector<int> &operations) {
    if (k == 1) {
        return 'a';
    }
    long long s = 1;
    int i;
    for (i = 0; i < operations.size(); ++i) {
        s *= 2;
        if (s >= k) {
            break;
        }
    }
    long long c = 0;
    while (i >= 0) {
        if (k > s / 2) {
            c += operations[i];
            k -= s / 2;
        }
        i--;
        s /= 2;
    }
    return c % 26 + 'a';
}