#include "bits/stdc++.h"

using namespace std;

long long countSubarrays(vector<int> &nums, long long k) {
    long long res = 0, sum = 0;
    int lef = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        while (sum * (i - lef + 1) >= k) {
            sum -= nums[lef];
            lef++;
        }
        res += i - lef + 1;
    }
    return res;
}