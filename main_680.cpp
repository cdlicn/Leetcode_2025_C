#include "bits/stdc++.h"

using namespace std;

bool f(string s, int lef, int rig) {
    while (lef < rig) {
        if (s[lef] != s[rig]) {
            return false;
        }
        lef++;
        rig--;
    }
    return true;
}

bool validPalindrome(string s) {
    int lef = 0, rig = s.size() - 1;
    while (lef < rig) {
        if (s[lef] == s[rig]) {
            lef++;
            rig--;
        } else {
            return f(s, lef + 1, rig) || f(s, lef, rig - 1);
        }
    }
    return true;
}