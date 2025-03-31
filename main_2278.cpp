#include "bits/stdc++.h"

using namespace std;

int percentageLetter(string s, char letter) {
    int n = 0;
    for (const auto &c: s) {
        if (c == letter) {
            n++;
        }
    }
    return 100 * n / s.size();
}