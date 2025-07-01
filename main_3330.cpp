#include "bits/stdc++.h"

using namespace std;

int possibleStringCount(string word) {
    int res = 1;
    for (int i = 1; i < word.size(); ++i) {
        res += word[i] == word[i - 1] ? 1 : 0;
    }
    return res;
}