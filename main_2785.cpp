#include "bits/stdc++.h"

using namespace std;

string sortVowels(string s) {
    vector<char> vs;
    for (const auto &c: s) {
        char lc = tolower(c);
        if (lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u') {
            vs.emplace_back(c);
        }
    }
    ranges::sort(vs);
    int idx = 0;
    for (int i = 0; i < s.size(); ++i) {
        char lc = tolower(s[i]);
        if (lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u') {
            s[i] = vs[idx++];
        }
    }
    return s;
}
