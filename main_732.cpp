#include "bits/stdc++.h"

using namespace std;

// TODO 732. 我的日程安排表 III
class MyCalendarThree {
public:
    MyCalendarThree() {

    }

    int book(int start, int end) {
        int ans = 0;
        int maxBook = 0;
        cnt[start]++;
        cnt[end]--;
        for (auto &[_, freq] : cnt) {
            maxBook += freq;
            ans = max(maxBook, ans);
        }
        return ans;
    }
private:
    map<int, int> cnt;
};