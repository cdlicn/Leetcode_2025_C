#include "bits/stdc++.h"

using namespace std;

long long validSubstringCount(string word1, string word2) {
    long long res = 0;
    if (word1.size() < word2.size()) {
        return res;
    }
    vector<int> diff(26, 0);
    for (const auto &c: word2) {
        diff[c - 'a']++;
    }
    int less = 0;
    for (const auto &v: diff) {
        if (v > 0) {
            less++;
        }
    }
    int lef = 0;
    for (int rig = 0; rig < word1.size(); rig++) {
        diff[word1[rig] - 'a']--;
        if (diff[word1[rig] - 'a'] == 0) {
            less--;
        }
        while (less == 0) {
            int lefChar = word1[lef];
            lef++;
            if (diff[lefChar - 'a'] == 0) {
                less++;
            }
            diff[lefChar - 'a']++;
        }
        res += lef;
    }
    return res;
}