#include "bits/stdc++.h"

using namespace std;

class ATM {
public:
    vector<int> money;
    vector<int> n;

    ATM() {
        money = {20, 50, 100, 200, 500};
        n.resize(5, 0);
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i <= 4; ++i) {
            n[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> res(5, 0);
        for (int i = 4; i >= 0; i--) {
            if (amount >= money[i]) {
                res[i] = min(n[i], amount / money[i]);
                amount -= res[i] * money[i];
            }

        }
        if (amount > 0) {
            return {-1};
        }
        for (int i = 0; i <= 4; ++i) {
            n[i] -= res[i];
        }
        return res;
    }
};