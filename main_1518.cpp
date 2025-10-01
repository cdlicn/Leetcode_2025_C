#include "bits/stdc++.h"

using namespace std;

int numWaterBottles(int numBottles, int numExchange) {
    int res = 0;
    while (numBottles >= numExchange) {
        res += numExchange;
        numBottles -= numExchange - 1;
    }
    return res + numBottles;
}