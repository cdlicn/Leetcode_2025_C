#include "bits/stdc++.h"

using namespace std;

int maxFrequencyElements(vector<int> &nums) {
    unordered_map<int, int> cnt;
    int mx = 0;
    int res = 0;
    for (const auto &num: nums) {
        cnt[num]++;
        if (cnt[num] > mx) {
            mx = cnt[num];
            res = cnt[num];
        } else if (cnt[num] == mx) {
            res += cnt[num];
        }
    }
    return res;
}