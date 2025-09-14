#include "bits/stdc++.h"

using namespace std;

string lowStr(string str) {
    for (auto &c: str) {
        c = tolower(c);
    }
    return str;
}

string changeStr(string str) {
    for (auto &c: str) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            c = '-';
        }
    }
    return str;
}

vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries) {
    unordered_set<string> origin_set(wordlist.begin(), wordlist.end());
    unordered_map<string, string> low_map;
    unordered_map<string, string> change_map;
    for (int i = wordlist.size() - 1; i >= 0; i--) {
        string word = wordlist[i];
        string lowS = lowStr(word);
        low_map[lowS] = word;
        change_map[changeStr(lowS)] = word;
    }
    vector<string> res;
    for (const auto &query: queries) {
        if (origin_set.contains(query)) {
            res.emplace_back(query);
            continue;
        }
        string lowQ = lowStr(query);
        if (low_map.contains(lowQ)) {
            res.emplace_back(low_map[lowQ]);
            continue;
        }
        string changeQ = changeStr(lowQ);
        if (change_map.contains(changeQ)) {
            res.emplace_back(change_map[changeQ]);
            continue;
        }
        res.emplace_back("");
    }
    return res;
}