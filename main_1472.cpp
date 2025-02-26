#include "bits/stdc++.h"

using namespace std;

class BrowserHistory {
public:
    vector<string> history;
    int cur = 0;

    BrowserHistory(string homepage) {
        history.push_back(homepage);
    }

    void visit(string url) {
        cur++;
        history.resize(cur);
        history.push_back(url);
    }

    string back(int steps) {
        return history[cur = max(cur - steps, 0)];
    }

    string forward(int steps) {
        return history[cur = min(cur + steps, (int) history.size() - 1)];
    }
};