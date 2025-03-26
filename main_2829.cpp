#include "bits/stdc++.h"

using namespace std;

int minimumSum(int n, int k) {
    vector<int> mp(k, 0);
    int res = 0;
    int val = 1;
    while (n) {
        if (val >= k || !mp[k - val]) {
            res += val;
            n--;
            if (val < k) {
                mp[val] = 1;
            }
        }
        val++;
    }
    return res;
}