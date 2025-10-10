#include "bits/stdc++.h"

using namespace std;

int maximumEnergy(vector<int> &energy, int k) {
    int res = INT_MIN / 2;
    for (int i = 0; i < energy.size(); ++i) {
        energy[i] = max((i - k < 0 ? INT_MIN / 2 : energy[i - k]) + energy[i], energy[i]);
        if(i >=  energy.size() - k) {
            res = max(res, energy[i]) ;
        }
    }
    return res;
}