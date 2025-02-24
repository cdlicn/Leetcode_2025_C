#include "bits/stdc++.h"

using namespace std;

class OrderedStream {
public:
    vector<string> stream;
    int prt = 0;

    OrderedStream(int n) {
        stream.resize(n);
    }

    vector<string> insert(int idKey, string value) {
        vector<string> res;
        stream[idKey - 1] = value;
        while (prt < stream.size() && !stream[prt].empty()) {
            res.push_back(stream[prt++]);
        }
        return res;
    }
};