#include "bits/stdc++.h"

using namespace std;

int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships) {
    int m = languages.size();
    vector<vector<bool>> ls(m, vector<bool>(n + 1, false));
    vector<int> cnt(n + 1, 0);
    int mx = 0;
    vector<bool> visited(m, false);

    for (int i = 0; i < languages.size(); ++i) {
        for (const auto &l: languages[i]) {
            ls[i][l] = true;
        }
    }

    int total = 0;

    auto add = [&](int i) -> void {
        if (visited[i]) {
            return;
        }
        visited[i] = true;
        total++;
        for (const auto &l: languages[i]) {
            cnt[l]++;
            mx = max(mx, cnt[l]);
        }
    };

    for (const auto &f: friendships) {
        int a = f[0] - 1, b = f[1] - 1;
        bool ok = false;
        for (const auto &al: languages[a]) {
            if (ls[b][al]) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            add(a);
            add(b);
        }
    }
    return total - mx;
}