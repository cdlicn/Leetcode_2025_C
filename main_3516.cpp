#include "bits/stdc++.h"

using namespace std;

int findClosest(int x, int y, int z) {
    int a = abs(x - z), b = abs(y - z);
    return a == b ? 0 : (a > b ? 2 : 1);
}