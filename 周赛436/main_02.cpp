#include "bits/stdc++.h"

using namespace std;

vector<int> assignElements(vector<int> &groups, vector<int> &elements) {
    int n = groups.size();
    int m = elements.size();
    unordered_map<int, int> mp;
    vector<int> res(n, -1);
    for (int i = 0; i < m; ++i) {
        if (!mp.count(elements[i])) {
            mp[elements[i]] = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        int group = groups[i];
        int minIdx = INT_MAX;
        for (int j = 1; j <= sqrt(group); j++) {
            if (group % j == 0) {
                if (mp.count(j)) {
                    minIdx = min(minIdx, mp[j]);
                }
                if (mp.count(group / j)) {
                    minIdx = min(minIdx, mp[group / j]);
                }
            }
        }
        res[i] = minIdx == INT_MAX ? -1 : minIdx;
    }
    return res;
}