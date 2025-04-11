#include "bits/stdc++.h"

using namespace std;

int countSymmetricIntegers(int low, int high) {
    int res = 0;
    for (int i = low; i <= high; i++) {
        string s = to_string(i);
        int n = s.size();
        if (n % 2 == 0 && reduce(s.begin(), s.begin() + n / 2) == reduce(s.begin() + n / 2, s.end())) {
            res++;
        }
    }
    return res;
}