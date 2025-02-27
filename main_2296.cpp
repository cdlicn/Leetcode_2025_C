#include "bits/stdc++.h"

using namespace std;

class TextEditor {
public:
    stack<char> lef, rig;

    TextEditor() {

    }

    void addText(string text) {
        for (const auto &c: text) {
            lef.emplace(c);
        }
    }

    int deleteText(int k) {
        int res = min((int) lef.size(), k);
        while (!lef.empty() && k != 0) {
            lef.pop();
            k--;
        }
        return res;
    }

    string cursorLeft(int k) {
        while (!lef.empty() && k != 0) {
            rig.emplace(lef.top());
            lef.pop();
            k--;
        }
        string res;
        int n = min(10, (int) lef.size());
        for (int i = 0; i < n; i++) {
            res = lef.top() + res;
            lef.pop();
        }
        for (const auto &c: res) {
            lef.emplace(c);
        }
        return res;
    }

    string cursorRight(int k) {
        while (!rig.empty() && k != 0) {
            lef.emplace(rig.top());
            rig.pop();
            k--;
        }
        string res;
        int n = min(10, (int) lef.size());
        for (int i = 0; i < n; i++) {
            res = lef.top() + res;
            lef.pop();
        }
        for (const auto &c: res) {
            lef.emplace(c);
        }
        return res;
    }
};