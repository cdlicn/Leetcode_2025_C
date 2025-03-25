#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector res(m, vector<int>(n, 0));
    unordered_set<int> st;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int x = i - 1, y = j - 1; x >= 0 && y >= 0; x--, y--) {
                st.emplace(grid[x][y]);
            }
            int top = st.size();
            st.clear();
            for (int x = i + 1, y = j + 1; x < m && y < n; x++, y++) {
                st.emplace(grid[x][y]);
            }
            int bot = st.size();
            st.clear();
            res[i][j] = abs(top - bot);
        }
    }
    return res;
}