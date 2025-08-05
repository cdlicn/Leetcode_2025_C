#include "bits/stdc++.h"

using namespace std;

int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
    int n = fruits.size(), res = n;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && fruits[i] <= baskets[j]) {
                res--;
                visited[j] = true;
                break;
            }
        }
    }
    return res;
}