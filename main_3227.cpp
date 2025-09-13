#include "bits/stdc++.h"

using namespace std;

bool doesAliceWin(string s) {
    for (const auto &c: s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
    }
    return false;
}