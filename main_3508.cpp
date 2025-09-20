#include "bits/stdc++.h"

using namespace std;

// TODO 3508. 设计路由器
struct TupleHash {
    template<typename T>
    static void hash_combine(size_t& seed, const T& v) {
        // 参考 boost::hash_combine
        seed ^= hash<T>{}(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }

    size_t operator()(const tuple<int, int, int>& t) const {
        auto& [a, b, c] = t;
        size_t seed = 0;
        hash_combine(seed, a);
        hash_combine(seed, b);
        hash_combine(seed, c);
        return seed;
    }
};

class Router {
    int memory_limit;
    queue<tuple<int, int, int>> packet_q; // packet 队列
    // 注：如果不想手写 TupleHash，可以用 set
    unordered_set<tuple<int, int, int>, TupleHash> packet_set; // packet 集合
    // deque 支持随机访问，方便二分
    unordered_map<int, deque<int>> dest_to_timestamps; // destination -> [timestamp]

public:
    Router(int memoryLimit) {
        memory_limit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        auto packet = tuple(source, destination, timestamp);
        if (!packet_set.insert(packet).second) { // packet 在 packet_set 中
            return false;
        }
        if (packet_q.size() == memory_limit) { // 太多了
            forwardPacket();
        }
        packet_q.push(packet); // 入队
        dest_to_timestamps[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (packet_q.empty()) {
            return {};
        }
        auto packet = packet_q.front(); // 出队
        packet_q.pop();
        packet_set.erase(packet);
        auto [source, destination, timestamp] = packet;
        dest_to_timestamps[destination].pop_front();
        return {source, destination, timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto& timestamps = dest_to_timestamps[destination];
        auto left = ranges::lower_bound(timestamps, startTime);
        auto right = ranges::upper_bound(timestamps, endTime);
        return right - left;
    }
};