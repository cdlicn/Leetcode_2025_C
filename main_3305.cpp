#include "bits/stdc++.h"

using namespace std;

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int countOfSubstrings(string word, int k) {
    unordered_map<char, int> cnt;
    int ks = 0;
    int lef = 0, rig = 0;
    int n = word.size();
    int cs = 0;
    long long res = 0;
    for (char v: "aeiou") {
        cnt[v] = 0;
    }

    int sum = 0;
    while (rig < n) {
        if (!isVowel(word[rig])) {
            ks++;
        } else {
            if (cnt[word[rig]] == 0) {
                cs++;
            }
            cnt[word[rig]]++;
        }
        if (!isVowel(word[rig])) {
            sum = 0;
        }
        while (ks >= k && cs == 5) {
            if (ks == k) {
                sum++;
            }
            if (!isVowel(word[lef])) {
                ks--;
            } else {
                cnt[word[lef]]--;
                if (cnt[word[lef]] == 0) {
                    cs--;
                }
            }
            lef++;
        }
        res += sum;
        rig++;
    }
    return res;
}