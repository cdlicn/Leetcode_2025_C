#include "bits/stdc++.h"

using namespace std;

// TODO 3272. 统计好整数的数目
long long countGoodIntegers(int n, int k) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] * i;
    }

    long long res = 0;
    unordered_set<string> vis;
    int base = pow(10, (n - 1) / 2);
    for (int i = base; i < base * 10; i++) { // 枚举回文数左半边
        string s = to_string(i);
        s += string(s.rbegin() + (n % 2), s.rend());
        if (stoll(s) % k) { // 回文数不能被 k 整除
            continue;
        }
        sort(s.begin(), s.end());
        if (!vis.insert(s).second) { // 不能重复统计
            continue;
        }

        int cnt[10]{};
        for (char c: s) {
            cnt[c - '0']++;
        }
        int tmp = (n - cnt[0]) * dp[n - 1];
        for (int c: cnt) {
            tmp /= dp[c];
        }
        res += tmp;
    }
    return res;
}