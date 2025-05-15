#include "bits/stdc++.h"

using namespace std;

vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups) {
    vector<string> res;
    int n = groups.size();
    for (int i = 0; i < n; ++i) {
        if (i == n - 1 || groups[i] != groups[i + 1]) {
            res.emplace_back(words[i]);
        }
    }
    return res;
}