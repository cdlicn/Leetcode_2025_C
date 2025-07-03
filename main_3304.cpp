#include "bits/stdc++.h"

using namespace std;

char kthCharacter(int k) {
    int v = 0;
    bitset<10> bit(k - 1);
    for (const auto c: bit.to_string()) {
        v += c == '1' ? 1 : 0;
    }
    return 'a' + v;
}