#include "bits/stdc++.h"

using namespace std;

int canBeTypedWords(string text, string brokenLetters) {
    vector<bool> err(26, false);
    for (const auto &c: brokenLetters) {
        err[c - 'a'] = true;
    }
    int res = 0;
    int ok = 1;
    for (const auto &c: text) {
        if (c == ' ') {
            res += ok;
            ok = 1;
            continue;
        }
        if (err[c - 'a'] && ok) {
            ok = 0;
        }
    }
    return res + ok;
}