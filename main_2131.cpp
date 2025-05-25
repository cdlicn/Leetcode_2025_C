#include "bits/stdc++.h"

using namespace std;

int longestPalindrome(vector<string> &words) {
    int res = 0;
    unordered_map<string, int> mp;
    for (const auto &w: words) {
        mp[w]++;
    }

    int m = 0;
    for (const auto &[w, n]: mp) {
        string rs = string(1, w[1]) + w[0];
        if (w == rs) {
            if (n % 2 == 1) {
                m = 2;
            }
            res += 2 * (n / 2 * 2);
        } else if (w > rs) {
            res += min(n, mp[rs]) * 4;
        }
    }
    return res + m;
}