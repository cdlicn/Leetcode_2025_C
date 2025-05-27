#include "bits/stdc++.h"

using namespace std;

int differenceOfSums(int n, int m) {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res += i % m ? i : -i;
    }
    return res;
}