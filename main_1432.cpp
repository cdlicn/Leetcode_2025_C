#include "bits/stdc++.h"

using namespace std;

int maxDiff(int num) {
    string n = to_string(num);
    string tmp = n;
    if (n[0] == '1') {
        for (auto &c: n) {
            if (c != '1') {
                ranges::replace(n, c, '0');
                break;
            }
        }
    } else {
        char c = n[0];
        ranges::replace(n, c, '1');
    }
    if (tmp[0] == '9') {
        for (auto &c: tmp) {
            if (c != '9') {
                ranges::replace(tmp, c, '9');
                break;
            }
        }
    } else {
        char c = tmp[0];
        ranges::replace(tmp, c, '9');
    }
    return stoi(tmp) - stoi(n);
}