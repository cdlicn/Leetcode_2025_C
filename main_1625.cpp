#include "bits/stdc++.h"

using namespace std;

// TODO 1625. 执行操作后字典序最小的字符串
string findLexSmallestString(string s, int a, int b) {
    int n = s.size();
    int step = gcd(b, n);
    int g = gcd(a, 10);
    string ans;

    for (int i = 0; i < n; i += step) {
        string t = s.substr(i) + s.substr(0, i); // 轮转

        auto modify = [&](int start) -> void {
            int ch = t[start] - '0'; // 最靠前的数字，越小越好
            // ch 可以变成的最小值为 ch%g
            // 例如 ch=5，g=2，那么 ch+2+2+2（模 10）后变成 1，不可能变得更小
            // 从 ch 到 ch%g，需要增加 inc，其中 +10 保证 inc 非负（循环中会 %10 保证结果在 [0,9] 中）
            int inc = ch % g - ch + 10;
            for (int j = start; j < n; j += 2) {
                t[j] = '0' + (t[j] - '0' + inc) % 10;
            }
        };

        modify(1); // 累加操作（所有奇数下标）
        if (step % 2) { // 能对偶数下标执行累加操作
            modify(0); // 累加操作（所有偶数下标）
        }

        if (ans.empty() || t < ans) {
            ans = move(t);
        }
    }

    return ans;
}