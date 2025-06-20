#include "bits/stdc++.h"

using namespace std;

int maxDistance(string s, int k) {
    int res = 0;
    int x = 0, y = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'N') {
            y++;
        } else if (s[i] == 'S') {
            y--;
        } else if (s[i] == 'E') {
            x++;
        } else {
            x--;
        }
        res = max(res, min(abs(x) + abs(y) + k * 2, i + 1));
    }
    return res;
}