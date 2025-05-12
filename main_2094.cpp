#include "bits/stdc++.h"

using namespace std;

vector<int> findEvenNumbers(vector<int> &digits) {
    vector<int> res;
    int cnt[10]{};
    for (const auto &d: digits) {
        cnt[d]++;
    }
    for (int i = 100; i < 1000; i += 2) {
        int s[10]{};
        bool b = true;
        for (int j = i; j > 0; j /= 10) {
            int x = j % 10;
            if (++s[x] > cnt[x]) {
                b = false;
                break;
            }
        }
        if (b) {
            res.emplace_back(i);
        }
    }
    return res;
}
