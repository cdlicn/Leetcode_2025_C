#include "bits/stdc++.h"

using namespace std;

void sortColors(vector<int> &nums) {
    int lef = 0, rig = nums.size() - 1;
    while (lef < rig) {
        while (lef < rig && nums[lef] == 0) {
            lef++;
        }
        while (lef < rig && nums[rig] != 0) {
            rig--;
        }
        int tmp = nums[lef];
        nums[lef] = nums[rig];
        nums[rig] = tmp;
    }
    lef = 0, rig = nums.size() - 1;
    while (lef < rig) {
        while (lef < rig && nums[lef] != 2) {
            lef++;
        }
        while (lef < rig && nums[rig] == 2) {
            rig--;
        }
        int tmp = nums[lef];
        nums[lef] = nums[rig];
        nums[rig] = tmp;
    }
}