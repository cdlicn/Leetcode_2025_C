#include "bits/stdc++.h"

using namespace std;

string makeFancyString(string s) {
    string res;
    int n = 1;
    res += s[0];
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            n++;
        } else {
            n = 1;
        }
        if (n <= 2) {
            res += s[i];
        }
    }
    return res;
}