#include "bits/stdc++.h"

using namespace std;

long long minSum(vector<int> &nums1, vector<int> &nums2) {
    long long s1 = 0, s2 = 0, n1 = 0, n2 = 0;
    for (const auto &n: nums1) {
        s1 += max(n, 1);
        if (n == 0) {
            n1++;
        }
    }
    for (const auto &n: nums2) {
        s2 += max(n, 1);
        if (n == 0) {
            n2++;
        }
    }
    if (!n1 && s1 < s2 || !n2 && s1 > s2) {
        return -1;
    }
    return max(s1, s2);
}