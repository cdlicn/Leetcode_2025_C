#include "bits/stdc++.h"

using namespace std;

string largestGoodInteger(string num) {
    char c;
    for (int i = 1; i < num.size() - 1; ++i) {
        if (c < num[i] && num[i - 1] == num[i] && num[i] == num[i + 1]) {
            c = num[i];
        }
    }
    return c ? string(3, c) : "";
}