#include "bits/stdc++.h"

using namespace std;

class Allocator {
public:
    vector<int> memo;

    Allocator(int n) {
        memo.resize(n, 0);
    }

    int allocate(int size, int mID) {
        int n = 0;
        for (int i = 0; i < memo.size(); ++i) {
            if (memo[i] != 0) {
                n = 0;
                continue;
            }
            n++;
            if (n == size) {
                for (int j = i - size + 1; j <= i; j++) {
                    memo[j] = mID;
                }
                return i - size + 1;
            }
        }
        return -1;
    }

    int freeMemory(int mID) {
        int res = 0;
        for (int &m: memo) {
            if (m == mID) {
                res++;
                m = 0;
            }
        }
        return res;
    }
};