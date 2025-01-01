#include "bits/stdc++.h"

using namespace std;

#include "bits/stdc++.h"

using namespace std;

string bin(int val) {
    string res = "";
    while (val) {
        res = (val & 1 ? "1" : "0") + res;
        val >>= 1;
    }
    return res;
}

string convertDateToBinary(string date) {
    return bin(stoi(date.substr(0, 4))) + "-" + bin(stoi(date.substr(5, 2))) + "-" + bin(stoi(date.substr(8, 2)));
}