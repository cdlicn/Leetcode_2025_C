#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> res;
vector<int> v;


void dfs(vector<int> &candidates, int i, int target) {
    if (target == 0) {
        res.push_back(v);
        return;
    }
    if (candidates.size() == i) {
        return;
    }
    int x = candidates[i];
    if (target < x) {
        return;
    }
    v.push_back(x);
    dfs(candidates, i + 1, target - x);
    v.pop_back();
    i++;
    while (i < candidates.size() && candidates[i] == x) {
        i++;
    }
    dfs(candidates, i, target);

}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    dfs(candidates, 0, target);
    return res;
}