#include "bits/stdc++.h"

using namespace std;

int generateKey(int num1, int num2, int num3) {
    int res = min({num1 % 10, num2 % 10, num3 % 10});
    num1 /= 10;
    num2 /= 10;
    num3 /= 10;
    res += 10 * min({num1 % 10, num2 % 10, num3 % 10});
    num1 /= 10;
    num2 /= 10;
    num3 /= 10;
    res += 100 * min({num1 % 10, num2 % 10, num3 % 10});
    num1 /= 10;
    num2 /= 10;
    num3 /= 10;
    res += 1000 * min({num1 % 10, num2 % 10, num3 % 10});
    return res;
}