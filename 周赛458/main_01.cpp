#include "bits/stdc++.h"

using namespace std;

string processStr(string s) {
    string res;
    for (const auto &c: s) {
        if (c == '*') {
            if (res == "") {
                continue;
            }
            res.erase(res.end() - 1);
        } else if (c == '#') {
            if (res == "") {
                continue;
            }
            res += res;
        } else if (c == '%') {
            reverse(res.begin(), res.end());
        } else {
            res += c;
        }
        cout << res << endl;
    }
    return res;
}