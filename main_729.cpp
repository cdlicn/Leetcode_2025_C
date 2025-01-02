#include "bits/stdc++.h"

using namespace std;

class MyCalendar {
public:
    set<pair<int, int>> st;

    MyCalendar() {

    }

    bool book(int startTime, int endTime) {
        auto it = st.lower_bound({endTime, 0});
        if (it == st.begin() || (--it)->second <= startTime) {
            st.emplace(startTime, endTime);
            return true;
        }
        return false;
    }
};