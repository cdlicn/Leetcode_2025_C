#include "bits/stdc++.h"

using namespace std;

int countPrefixes(vector<string> &words, string s) {
    int res = 0;
    for (const auto &word: words) {
        if (word.size() <= s.size() && word == s.substr(0, word.size())) {
            res++;
        }
    }
    return res;
}