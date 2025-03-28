#include "bits/stdc++.h"

using namespace std;

int minimizedStringLength(string s) {
    vector<int> cs(26, 0);
    int res = 0;
    for (const auto &c: s) {
        if (!cs[c - 'a']) {
            res++;
            cs[c - 'a']++;
        }
    }
    return res;
}