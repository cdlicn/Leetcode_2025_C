#include "bits/stdc++.h"

using namespace std;

vector<int> lexicalOrder(int n) {
    vector<int> res(n);
    int v = 1, i = 0;
    while (i < n) {
        res[i++] = v;
        if (v * 10 <= n) {
            v *= 10;
        } else {
            while (v % 10 == 9 || v + 1 > n) {
                v /= 10;
            }
            v++;
        }
    }
    return res;
}