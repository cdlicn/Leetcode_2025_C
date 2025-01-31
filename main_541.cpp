#include "bits/stdc++.h"

using namespace std;


string reverseStr(string s, int k) {
    for (int i = 0; i < s.size(); i += 2 * k) {
        int len = s.size() - i;
        int m = min(k, len);
        reverse(s.begin() + i, s.begin() + i + m);
    }
    return s;
}