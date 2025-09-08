#include "bits/stdc++.h"

using namespace std;

vector<int> getNoZeroIntegers(int n) {
    int a = 0;
    int x = 1;
    for (int i = n; i > 1; i /= 10) {
        int v = i % 10;
        if (v == 0) {
            a += 5 * x;
            i -= 10;
        } else if (v == 1) {
            a += 5 * x;
            i -= 10;
        } else {
            a += v / 2 * x;
        }
        x *= 10;
    }
    return {a, n - a};
}