#include "bits/stdc++.h"

using namespace std;


long long calculateScore(string s) {
    long long res = 0;
    vector<set<int>> vs(26);
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        vs[s[i] - 'a'].insert(i);
    }
    for (int i = 0; i < s.size(); ++i) {
        char nowC = s[i];
        char needC = 'z' - (nowC - 'a');
        int needIdx = needC - 'a';

        if (!vs[needIdx].empty()) {
            set<int> idxs = vs[needIdx];
            auto it = idxs.lower_bound(i);
            if (it != idxs.begin()) {
                it--;
                int j = *it;
                res += i - j;
                idxs.erase(j);
                vs[nowC - 'a'].erase(i);
            }
        }
    }
    return res;
}

long long calculateScore(string s) {
    long long res = 0;
    vector<set<int>> vs(26);
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        vs[s[i] - 'a'].insert(i);
    }
    for (int i = 0; i < n; ++i) {
        char nowC = s[i];
        char needC = 'z' - (nowC - 'a');
        int needIdx = needC - 'a';

        if (!vs[needIdx].empty()) {
            auto& idxs = vs[needIdx];
            auto it = idxs.lower_bound(i);
            if (it != idxs.begin()) {
                --it;
                int j = *it;
                res += i - j;
                // Mark position j as used by removing it from the set
                idxs.erase(it);
                // Mark position i as used by removing it from the set
                vs[nowC - 'a'].erase(i);
            }
        }
    }

    return res;
}