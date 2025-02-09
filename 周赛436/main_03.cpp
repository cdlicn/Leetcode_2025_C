#include "bits/stdc++.h"

using namespace std;

long long res = 0;

int judge(string n) {
    int val = stoi(n);
    return (val != 0 && val % 10 != 0 && val % (val % 10) == 0) ? 1 : 0;
}

void dfs(string s, string n, int i) {
    if (i == s.size()) {
        return;
    }
    res += judge(n);
    dfs(s, "0", i + 1);
    dfs(s, n + s[i], i + 1);
}

long long countSubstrings(string s) {
    dfs(s, "0", 0);
    return res;
}