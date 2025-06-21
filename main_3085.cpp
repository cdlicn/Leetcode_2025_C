#include "bits/stdc++.h"

using namespace std;

int minimumDeletions(string word, int k) {
    int n = 0;
    vector<int> cnt(26, 0);
    for (const auto &c: word) {
        cnt[c - 'a']++;
    }
    ranges::sort(cnt);
    for (int i = 0; i < 26; i++) {
        int x = 0;
        for (int j = i; j < 26; j++) {
            x += min(cnt[j], cnt[i] + k);
        }
        n = max(n, x);
    }
    return word.size() - n;
}