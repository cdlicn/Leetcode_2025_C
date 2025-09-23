#include "bits/stdc++.h"

using namespace std;

int compareVersion(string version1, string version2) {
    int i1 = 0, i2 = 0;
    while (i1 < version1.size() || i2 < version2.size()) {
        int a = 0, b = 0;
        while (i1 < version1.size() && version1[i1] != '.') {
            a = 10 * a + (version1[i1] - '0');
            i1++;
        }
        i1++;
        while (i2 < version2.size() && version2[i2] != '.') {
            b = 10 * b + (version2[i2] - '0');
            i2++;
        }
        i2++;
        if (a > b) {
            return 1;
        }
        if (b > a) {
            return -1;
        }
    }
    return 0;
}