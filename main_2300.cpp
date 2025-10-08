#include "bits/stdc++.h"

using namespace std;

vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
    ranges::sort(potions);
    int n = spells.size();
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        int spell = spells[i];
        long long x = (success + spell - 1) / spell - 1;
        auto v = upper_bound(potions.begin(), potions.end(), x);
        res[i] = potions.end() - v;
    }
    return res;
}