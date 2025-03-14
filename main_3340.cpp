#include "bits/stdc++.h"

using namespace std;

bool isBalanced(string num) {
    int sum = 0;
    for (int i = 0; i < num.size(); ++i) {
        int n = num[i] - '0';
        sum += i % 2 == 0 ? n : -n;
    }
    return sum == 0;
}