#include "bits/stdc++.h"

using namespace std;

string breakPalindrome(string palindrome) {
    if (palindrome.size() == 1) {
        return "";
    }
    int n = palindrome.size();
    for (int i = 0; i < n; ++i) {
        if (!(n % 2 == 1 && i == n / 2) && palindrome[i] != 'a') {
            palindrome[i] = 'a';
            return palindrome;
        }
    }
    palindrome[palindrome.size() - 1] = 'b';
    return palindrome;
}