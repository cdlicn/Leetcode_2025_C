#include "bits/stdc++.h"

using namespace std;

int removeDuplicates(vector<int> &nums) {
    if (nums.size() <= 2) {
        return nums.size();
    }
    int slow = 2;
    int fast = 2;
    for (int i = 2; i < nums.size(); i++) {
        if (nums[slow - 2] != nums[fast]) {
            nums[slow++] = nums[fast];
        }
        fast++;
    }
    return slow;
}