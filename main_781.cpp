#include "bits/stdc++.h"

using namespace std;

int numRabbits(vector<int> &answers) {
    unordered_map<int, int> mp;
    for (const auto &answer: answers) {
        mp[answer]++;
    }
    int res = 0;
    for (const auto &[k, v]: mp) {
        res += ceil(v / (k + 1.0)) * (k + 1.0);
    }
    return res;
}