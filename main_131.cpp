#include "bits/stdc++.h"

using namespace std;

bool judge(string s) {
    int lef = 0, rig = s.size() - 1;
    while (lef < rig) {
        if (s[lef++] != s[rig--]) {
            return false;
        }
    }
    return true;
}

vector<vector<string>> res;

void dfs(vector<string> vs, string s, string nowStr, int i) {
    if (i == s.size()) {
        if (nowStr == "") {
            res.push_back(vs);
        }
        return;
    }
    dfs(vs, s, nowStr + s[i], i + 1);
    if (judge(nowStr + s[i])) {
        vs.push_back(nowStr + s[i]);
        dfs(vs, s, "", i + 1);
    }
}

vector<vector<string>> partition(string s) {
    dfs(vector<string>(), s, "", 0);
    return res;
}