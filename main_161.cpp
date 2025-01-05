#include "bits/stdc++.h"

using namespace std;

bool f(string s1, string s2) {
    int l1 = s1.size(), l2 = s2.size();
    int idx1 = 0, idx2 = 0;
    while (idx1 < l1 && idx2 < l2) {
        if (s1[idx1] == s2[idx2]) {
            idx1++;
        }
        idx2++;
        if (idx2 - idx1 > 1) {
            return false;
        }
    }
    return true;
}

bool isOneEditDistance(string s, string t) {
    int m = s.size(), n = t.size();
    if (abs(m - n) > 1) {
        return false;
    }
    if (n - m == 1) {
        return f(s, t);
    } else if (m - n == 1) {
        return f(t, s);
    } else if (m == n) {
        bool foundDifference = false;
        for (int i = 0; i < m; i++) {
            if (s[i] != t[i]) {
                if (!foundDifference) {
                    foundDifference = true;
                } else {
                    return false;
                }
            }
        }
        return foundDifference;
    } else {
        return false;
    }
}
