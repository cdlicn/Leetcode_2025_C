#include "bits/stdc++.h"

using namespace std;

int minimumSum(int num) {
    vector<int> v;
    while (num) {
        v.emplace_back(num % 10);
        num /= 10;
    }
    sort(v.begin(), v.end());
    return v[2] + v[3] + 10 * (v[0] + v[1]);
}