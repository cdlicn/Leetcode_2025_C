#include "bits/stdc++.h"

using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> c[rowIndex + 1];
    for (int i = 0; i < rowIndex + 1; ++i) {
        c[i].resize(i + 1, 1);
        for (int j = 1; j < i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    return c[rowIndex];
}