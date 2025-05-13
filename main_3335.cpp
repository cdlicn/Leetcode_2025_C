#include "bits/stdc++.h"

using namespace std;

int lengthAfterTransformations(string s, int t) {
    int MOD = 1e9 + 7;
    int cnt[26]{0};
    for (const auto &c: s) {
        cnt[c - 'a']++;
    }
    for (int i = 0; i < t; ++i) {
        int nxt[26]{0};
        for (int j = 1; j < 26; ++j) {
            nxt[j] = cnt[j - 1];
        }
        nxt[0] = cnt[25];
        nxt[1] = (cnt[25] + nxt[1]) % MOD;
        for (int j = 0; j < 26; ++j) {
            cnt[j] = nxt[j];
        }
    }
    int res = 0;
    for (int i : cnt) {
        res = (res + i) % MOD;
    }
    return res;
}