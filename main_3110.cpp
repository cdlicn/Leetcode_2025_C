#include "bits/stdc++.h"

using namespace std;

int scoreOfString(string s) {
    int res = 0;
    for (int i = 1; i < s.size(); ++i) {
        res += abs(s[i] - s[i - 1]);
    }
    return res;
}