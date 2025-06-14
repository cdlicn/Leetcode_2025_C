#include "bits/stdc++.h"

using namespace std;

int minMaxDifference(int num) {
    string s = to_string(num);
    int mx = num;
    for (char c: s) {
        if (c != '9') {
            string tmp = s;
            ranges::replace(tmp, c, '9');
            mx = stoi(tmp);
            break;
        }
    }

    char s0 = s[0];
    ranges::replace(s, s0, '0');
    int mn = stoi(s);

    return mx - mn;
}