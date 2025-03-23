#include "bits/stdc++.h"

using namespace std;

bool canBeValid(string s, string locked) {
    int n = s.size();
    if (n % 2 == 1) {
        return false;
    }
    int mn = 0, mx = 0;
    for (int i = 0; i < n; ++i) {
        if (locked[i] == '1') {
            if (s[i] == '(') {
                mn++;
                mx++;
            } else {
                mn--;
                mx--;
            }
        } else {
            mn--;
            mx++;
        }
        if (mn < 0) {
            mn = 1;
        }
        if (mx < 0) {
            return false;
        }
    }
    return mn == 0;
}