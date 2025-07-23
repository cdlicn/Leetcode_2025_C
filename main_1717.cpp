#include "bits/stdc++.h"

using namespace std;

int maximumGain(string s, int x, int y) {
    char a = 'a', b = 'b';
    if (x < y) {
        swap(x, y);
        swap(a, b);
    }

    int cnt1 = 0, cnt2 = 0, res = 0;
    for (const auto &c: s) {
        if (c == a) {
            cnt1++;
        } else if (c == b) {
            if (cnt1 > 0) {
                cnt1--;
                res += x;
            } else {
                cnt2++;
            }
        } else {
            res += min(cnt1, cnt2) * y;
            cnt1 = 0;
            cnt2 = 0;
        }
    }
    return res + min(cnt1, cnt2) * y;
}