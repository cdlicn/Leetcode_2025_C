#include "bits/stdc++.h"

using namespace std;

int maxConsecutive(int bottom, int top, vector<int> &special) {
    sort(special.begin(), special.end());
    int res = max(special[0] - bottom, top - special[special.size() - 1]);
    for (int i = 1; i < special.size(); ++i) {
        res = max(special[i] - special[i - 1] - 1, res);
    }
    return res;
}