#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> memo;

int dfs(int i, int j, string floor, int carpetLen) {
    if (j < carpetLen * i) {
        return 0;
    }
    int &res = memo[i][j];
    if (res != -1) {
        return res;
    }
    if (i == 0) {
        return res = dfs(i, j - 1, floor, carpetLen) + (floor[j] - '0');
    }
    return res = min(dfs(i, j - 1, floor, carpetLen) + (floor[j] - '0'),
                     dfs(i - 1, j - carpetLen, floor, carpetLen));
}

int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
    int m = floor.size();
    memo.resize(numCarpets + 1, vector<int>(m, -1));
    return dfs(numCarpets, m - 1, floor, carpetLen);
}