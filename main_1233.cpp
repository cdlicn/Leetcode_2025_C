#include "bits/stdc++.h"

using namespace std;

vector<string> removeSubfolders(vector<string> &folder) {
    sort(folder.begin(), folder.end());
    int i = 1, n = folder.size();
    vector<string> res;
    res.emplace_back(folder[0]);
    while (i < n) {
        string str = *(res.end() - 1);
        if (!folder[i].starts_with(str) || folder[i][str.size()] != '/') {
            res.emplace_back(folder[i]);
        }
        i++;
    }
    return res;
}