#include "bits/stdc++.h"

using namespace std;

class NumberContainers {
public:

    unordered_map<int, set<int>> mp;
    unordered_map<int, int> nums;

    NumberContainers() {

    }

    void change(int index, int number) {
        if (nums.contains(index)) {
            mp[nums[index]].erase(index);
        }
        nums[index] = number;
        mp[number].emplace(index);
    }

    int find(int number) {
        if (mp.contains(number) && !mp[number].empty()) {
            return *mp[number].begin();
        }
        return -1;
    }
};