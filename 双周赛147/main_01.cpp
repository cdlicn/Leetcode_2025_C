#include "bits/stdc++.h"

using namespace std;

bool hasMatch(string s, string p) {
    if (p.size() == 1) {
        return true;
    }
    string s1 = "";
    string s2 = "";
    bool b = true;
    for (const auto &c: p) {
        if (c == '*') {
            b = false;
            continue;
        }
        if (b) {
            s1 += c;
        } else {
            s2 += c;
        }
    }
    if (s1.empty() && s2.empty()) {
        return true;
    }
    if (s1.empty() && s.find(s2) != string::npos) {
        return true;
    }
    if (s2.empty() && s.find(s1) != string::npos) {
        return true;
    }
    if (s.find(s1) != string::npos && s.find(s2) != string::npos && s.find(s1) + s1.size() <= strrchr(s, s2)) {
        return true;
    }
    return false;
}