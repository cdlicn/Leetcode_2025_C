#include "bits/stdc++.h"

using namespace std;

int
maxCandies(vector<int> &status, vector<int> &candies, vector<vector<int>> &keys, vector<vector<int>> &containedBoxes,
           vector<int> &initialBoxes) {
    int res = 0;
    int n = status.size();
    vector<int> &has_key = status;
    vector<bool> has_box(n);
    for (int x: initialBoxes) {
        has_box[x] = true;
    }
    auto dfs = [&](auto &&dfs, int i) -> void {
        res += candies[i];
        has_box[i] = false;

        for (const auto &box: keys[i]) {
            has_key[box] = true;
            if (has_box[box]) {
                dfs(dfs, box);
            }
        }

        for (const auto &box: containedBoxes[i]) {
            has_box[box] = true;
            if (has_key[box]) {
                dfs(dfs, box);
            }
        }
    };

    for (const auto &box: initialBoxes) {
        if (has_key[box] && has_box[box]) {
            dfs(dfs, box);
        }
    }
    return res;
}