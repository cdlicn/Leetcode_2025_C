#include "bits/stdc++.h"

using namespace std;

vector<int> evenOddBit(int n) {
    int even = 0, odd = 0;
    bool b = true;
    while (n) {
        if (b) {
            even += n & 1;
        } else {
            odd += n & 1;
        }
        b = !b;
        n >>= 1;
    }
    return {even, odd};
}