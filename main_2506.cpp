#include "bits/stdc++.h"

using namespace std;


int similarPairs(vector<string> &words) {
    unordered_map<int, int> mp;
    int res = 0;
    for (const auto &word: words) {
        int n = 0;
        for (const auto &c: word) {
            n |= 1 << (c - 'a');
        }
        res += mp[n]++;
    }
    return res;
}