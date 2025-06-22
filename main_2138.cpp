#include "bits/stdc++.h"

using namespace std;

vector<string> divideString(string s, int k, char fill) {
    vector<string> res;
    while (s.size() % k != 0) {
        s += fill;
    }
    while (s.size()) {
        res.emplace_back(s.substr(0, k));
        s = s.substr(k);
    }
    return res;
}
