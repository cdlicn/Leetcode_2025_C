#include "bits/stdc++.h"

using namespace std;

bool isValid(string word) {
    if (word.size() < 3) {
        return false;
    }
    bool a = false, b = false;
    for (const auto &c: word) {
        if (!isalpha(c) && !isalnum(c)) {
            return false;
        }
        if (!isalpha(c)) {
            continue;
        }
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'
                ) {
            a = true;
        } else {
            b = true;
        }
    }
    return a && b;
}