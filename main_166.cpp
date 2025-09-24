#include "bits/stdc++.h"

using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    bool b = ((numerator >= 0 && denominator >= 0) || (numerator <= 0 && denominator <= 0));
    long long aV = abs((long long)numerator);
    long long bV = abs((long long)denominator);
    unordered_map<int, int> idx;
    string res;
    res += to_string(aV / bV);
    if (aV % bV == 0) {
        return b ? res : "-" + res;
    }
    res += ".";
    aV = aV - aV / bV * bV;
    int i = res.size();
    while (aV) {
        aV *= 10;
        if (idx.contains(aV)) {
            res.insert(res.begin() + idx[aV], '(');
            res += ')';
            return b ? res : "-" + res;
        }
        idx[aV] = i;
        if (aV > bV) {
            res += to_string(aV / bV);
            aV = aV - aV / bV * bV;
        } else {
            res += '0';
        }
        i++;
    }
    return b ? res : "-" + res;
}