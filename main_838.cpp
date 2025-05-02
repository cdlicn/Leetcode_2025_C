#include "bits/stdc++.h"

using namespace std;

string pushDominoes(string dominoes) {
    dominoes = "L" + dominoes + "R";
    int pre = 0;
    for (int i = 1; i < dominoes.size(); ++i) {
        if (dominoes[i] == '.') {
            continue;
        }
        if (dominoes[i] == dominoes[pre]) {
            fill(dominoes.begin() + pre + 1, dominoes.begin() + i, dominoes[i]);
        } else if (dominoes[i] == 'L') {
            fill(dominoes.begin() + pre + 1, dominoes.begin() + (pre + i + 1) / 2, 'R');
            fill(dominoes.begin() + (pre + i) / 2 + 1, dominoes.begin() + i, 'L');
        }
        pre = i;
    }
    return dominoes.substr(1, dominoes.size() - 2);
}