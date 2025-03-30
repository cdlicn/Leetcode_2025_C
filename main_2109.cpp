#include "bits/stdc++.h"

using namespace std;

string addSpaces(string s, vector<int> &spaces) {
    string res;
    int n = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (n < spaces.size() && spaces[n] == i) {
            res += ' ';
            n++;
        }
        res += s[i];
    }
    return res;
}