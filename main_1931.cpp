#include "bits/stdc++.h"

using namespace std;

// TODO 1931. 用三种不同颜色为网格涂色
const int MOD = 1'000'000'007;

int colorTheGrid(int m, int n) {
    vector<int> pow3(m);
    pow3[0] = 1;
    for (int i = 1; i < m; i++) {
        pow3[i] = pow3[i - 1] * 3;
    }

    vector<int> valid;
    for (int color = 0; color < pow3[m - 1] * 3; color++) {
        bool ok = true;
        for (int i = 1; i < m; i++) {
            if (color / pow3[i] % 3 == color / pow3[i - 1] % 3) { // 相邻颜色相同
                ok = false;
                break;
            }
        }
        if (ok) {
            valid.push_back(color);
        }
    }

    int nv = valid.size();
    vector<vector<int>> nxt(nv);
    for (int i = 0; i < nv; i++) {
        for (int j = 0; j < nv; j++) {
            bool ok = true;
            for (int k = 0; k < m; k++) {
                if (valid[i] / pow3[k] % 3 == valid[j] / pow3[k] % 3) { // 相邻颜色相同
                    ok = false;
                    break;
                }
            }
            if (ok) {
                nxt[i].push_back(j);
            }
        }
    }

    vector f(n, vector<int>(nv));
    ranges::fill(f[0], 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < nv; j++) {
            for (int k: nxt[j]) {
                f[i][j] = (f[i][j] + f[i - 1][k]) % MOD;
            }
        }
    }

    long long ans = 0;
    for (int j = 0; j < nv; j++) {
        ans += f[n - 1][j];
    }
    return ans % MOD;
}