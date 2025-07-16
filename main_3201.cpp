#include "bits/stdc++.h"

using namespace std;

int maximumLength(vector<int> &nums) {
    int r1 = 0;
    int r2 = 0;
    int r3 = 0;
    int r4 = 0;
    for (auto &num: nums) {
        if (num % 2 == 0) {
            if (r1 % 2 == 1) {
                r1++;
            }
            if (r2 % 2 == 0) {
                r2++;
            }
            r3++;
        } else {
            if (r1 % 2 == 0) {
                r1++;
            }
            if (r2 % 2 == 1) {
                r2++;
            }
            r4++;
        }
    }
    return max({r1, r2, r3, r4});
}