#include "bits/stdc++.h"

using namespace std;

vector<int> sortArrayByParity(vector<int> &nums) {
    int a = 0, b = nums.size() - 1;
    while (a < b) {
        while (a < b && nums[a] % 2 == 0) {
            a++;
        }
        while (a < b && nums[b] % 2 == 1) {
            b--;
        }
        if (a < b) {
            swap(nums[a], nums[b]);
        }
    }
    return nums;
}