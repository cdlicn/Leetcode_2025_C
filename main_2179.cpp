#include "bits/stdc++.h"

using namespace std;

// TODO 2179. 统计数组中好三元组数目
template<typename T>
class FenwickTree {
    vector<T> tree;

public:
    // 使用下标 1 到 n
    FenwickTree(int n) : tree(n + 1) {}

    // a[i] 增加 val
    // 1 <= i <= n
    void update(int i, T val) {
        for (; i < tree.size(); i += i & -i) {
            tree[i] += val;
        }
    }

    // 求前缀和 a[1] + ... + a[i]
    // 1 <= i <= n
    T pre(int i) const {
        T res = 0;
        for (; i > 0; i &= i - 1) {
            res += tree[i];
        }
        return res;
    }
};

long long goodTriplets(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[nums1[i]] = i;
    }

    long long ans = 0;
    FenwickTree<int> t(n);
    for (int i = 0; i < n - 1; i++) {
        int y = p[nums2[i]];
        int less = t.pre(y);
        ans += 1LL * less * (n - 1 - y - (i - less));
        t.update(y + 1, 1);
    }
    return ans;
}