#include "bits/stdc++.h"

using namespace std;

int countLargestGroup(int n) {
    unordered_map<int, int> mp;
    int mx = 0, res = 0;
    for (int i = 1; i <= n; i++) {
        int s = 0, x = i;
        while (x) {
            s += x % 10;
            x /= 10;
        }
        mp[s]++;
        if (mp[s] > mx) {
            mx = mp[s];
            res = 1;
        } else if (mp[s] == mx) {
            res++;
        }
    }
    return res;
}