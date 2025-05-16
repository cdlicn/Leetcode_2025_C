#include "bits/stdc++.h"

using namespace std;

// TODO 2901. 最长相邻不相等子序列 II
bool ok(string &s, string &t) {
    if (s.size() != t.size()) {
        return false;
    }
    bool diff = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
            if (diff) { // 汉明距离大于 1
                return false;
            }
            diff = true;
        }
    }
    return diff;
}

vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups) {
    int n = words.size();
    vector<int> f(n), from(n);
    int max_i = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            // 提前比较 f[j] 与 f[i] 的大小，如果 f[j] <= f[i]，就不用执行更耗时的 check 了
            if (f[j] > f[i] && groups[j] != groups[i] && ok(words[i], words[j])) {
                f[i] = f[j];
                from[i] = j;
            }
        }
        f[i]++; // 加一写在这里
        if (f[i] > f[max_i]) {
            max_i = i;
        }
    }

    int i = max_i;
    int m = f[i];
    vector<string> ans(m);
    for (int k = 0; k < m; k++) {
        ans[k] = words[i];
        i = from[i];
    }
    return ans;
}