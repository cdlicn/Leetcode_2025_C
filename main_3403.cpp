#include "bits/stdc++.h"

using namespace std;

string answerString(string word, int numFriends) {
    if(numFriends == 1) {
        return word;
    }
    string res;
    int n = word.size();
    for (int i = 0; i < n; ++i) {
        res = max(res, word.substr(i, n - max(numFriends - 1, i)));
    }
    return res;
}