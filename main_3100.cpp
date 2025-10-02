#include "bits/stdc++.h"

using namespace std;

int maxBottlesDrunk(int numBottles, int numExchange) {
    int res = numBottles;
    while (numBottles >= numExchange) {
        numBottles = numBottles - numExchange + 1;
        res += 1;
        numExchange++;
    }
    return res;
}