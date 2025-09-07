#include "bits/stdc++.h"

using namespace std;

vector<int> sumZero(int n) {
    vector<int> v;
    if (n % 2) {
        v.emplace_back(0);
    }
    for (int i = 1; i <= n / 2; ++i) {
        v.emplace_back(i);
        v.emplace_back(-i);
    }
    return v;
}