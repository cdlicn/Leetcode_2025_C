#include "bits/stdc++.h"

using namespace std;

class TaskManager {
private:
    unordered_map<int, pair<int, int>> info;
    set<pair<int, int>, greater<>> st;

public:
    TaskManager(vector<vector<int>> &tasks) {
        for (const auto &task: tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];
            add(userId, taskId, priority);
        }
    }

    void add(int userId, int taskId, int priority) {
        info[taskId] = {userId, priority};
        st.insert({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        int old = info[taskId].second;
        st.erase({old, taskId});
        info[taskId].second = newPriority;
        st.insert({newPriority, taskId});
    }

    void rmv(int taskId) {
        int priority = info[taskId].second;
        st.erase({priority, taskId});
        info.erase(taskId);
    }

    int execTop() {
        if (st.empty()) {
            return -1;
        }
        pair<int, int> task = *st.begin();
        int taskId = task.second;
        st.erase(task);
        int res = info[taskId].first;
        info.erase(taskId);
        return res;
    }
};