#include "bits/stdc++.h"

using namespace std;

int minSwaps(string s) {
    int n = 0;
    for (const auto &c: s) {
        if (c == '[' || n == 0) {
            n++;
        } else {
            n--;
        }
    }
    return n / 2;
}