#include "bits/stdc++.h"

using namespace std;

int divisorSubstrings(int num, int k) {
    int n = 0, bn = num;
    for (int i = 0; i < k; ++i) {
        n += pow(10, i) * (num % 10);
        num /= 10;
    }
    int res = n != 0 && bn % n == 0;
    while (num) {
        n /= 10;
        n += pow(10, k - 1) * (num % 10);
        num /= 10;
        res += n != 0 && bn % n == 0;
    }
    return res;
}