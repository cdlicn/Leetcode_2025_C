#include "bits/stdc++.h"

using namespace std;

int countKeyChanges(string s) {
    int res = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != s[i - 1] && s[i] != s[i - 1] - 'A' + 'a' && s[i - 1] != s[i] - 'A' + 'a') {
            res++;
        }
    }
    return res;
}