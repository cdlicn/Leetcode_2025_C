#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    res.emplace_back(vector<int>{1});
    for (int i = 1; i < numRows; i++) {
        vector<int> tmp;
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                tmp.emplace_back(1);
            } else {
                tmp.emplace_back(res[i - 1][j] + res[i - 1][j - 1]);
            }
        }
        res.emplace_back(tmp);
    }
    return res;
}