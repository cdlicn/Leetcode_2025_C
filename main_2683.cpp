#include "bits/stdc++.h"

using namespace std;

bool doesValidArrayExist(vector<int> &derived) {
    int v = derived[0];
    for (int i = 1; i < derived.size(); ++i) {
        v ^= derived[i];
    }
    return v == 0;
}