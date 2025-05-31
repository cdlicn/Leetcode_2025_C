#include "bits/stdc++.h"

using namespace std;

// TODO 909. 蛇梯棋
int snakesAndLadders(vector<vector<int>> &board) {
    int n = board.size();
    vector<int> vis(n * n + 1);
    vis[1] = true;
    vector<int> q = {1};
    for (int step = 0; !q.empty(); step++) {
        auto tmp = q;
        q.clear();
        for (int x: tmp) {
            if (x == n * n) {
                return step;
            }
            for (int y = x + 1; y <= min(x + 6, n * n); y++) {
                int r = (y - 1) / n, c = (y - 1) % n;
                if (r % 2) {
                    c = n - 1 - c;
                }
                int nxt = board[n - 1 - r][c];
                if (nxt < 0) {
                    nxt = y;
                }
                if (!vis[nxt]) {
                    vis[nxt] = true;
                    q.push_back(nxt);
                }
            }
        }
    }
    return -1; // 无法到达终点
}