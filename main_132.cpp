#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> memo;
vector<int> resMemo;

bool judge(const string &s, int lef, int rig) {
    if (lef >= rig) {
        return true;
    }
    int &res = memo[lef][rig];
    if (res != -1) {
        return res;
    }
    return res = s[lef] == s[rig] && judge(s, lef + 1, rig - 1);
}

int dfs(const string &s, int i) {
    if (judge(s, 0, i)) {
        return 0;
    }
    int &res = resMemo[i];
    if (res != INT_MAX) {
        return res;
    }
    for (int l = 1; l <= i; l++) {
        if (judge(s, l, i)) {
            res = min(res, dfs(s, l - 1) + 1);
        }
    }
    return res;
}

int minCut(string s) {
    int n = s.size();
    memo.resize(n, vector<int>(n, -1));
    resMemo.resize(n, INT_MAX);
    return dfs(s, n - 1);
}