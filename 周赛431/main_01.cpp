#include "bits/stdc++.h"

using namespace std;

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int maxLength(vector<int> &nums) {
    int n = nums.size();
    int res = 0;

    for (int i = 0; i < n; ++i) {
        long long x = 1;
        int g = nums[i];
        int l = nums[i];
        for (int j = i; j < n; ++j) {
            if (x > LLONG_MAX / nums[j]) {
                break;
            }
            x *= nums[j];
            g = gcd(g, nums[j]);
            l = lcm(l, nums[j]);

            if (x == 1LL * l * g) {
                res = max(res, j - i + 1);
            }
        }
    }
    return res;
}