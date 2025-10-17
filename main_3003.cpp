#include "bits/stdc++.h"

using namespace std;

// TODO 3003. 执行操作后的最大分割数量
int maxPartitionsAfterOperations(string s, int k) {
    unordered_map<long long, int> memo;
    auto dfs = [&](this auto &&dfs, int i, int mask, bool changed) -> int {
        if (i == s.length()) {
            return 1;
        }

        // 把参数压缩到一个 long long 中，方便作为哈希表的 key
        long long args = (long long) i << 32 | mask << 1 | changed;
        auto it = memo.find(args);
        if (it != memo.end()) { // 之前计算过
            return it->second;
        }

        int res;
        // 不改 s[i]
        int bit = 1 << (s[i] - 'a');
        int new_mask = mask | bit;
        if (popcount((uint32_t) new_mask) > k) {
            // 分割出一个子串，这个子串的最后一个字母在 i-1
            // s[i] 作为下一段的第一个字母，也就是 bit 作为下一段的 mask 的初始值
            res = dfs(i + 1, bit, changed) + 1;
        } else { // 不分割
            res = dfs(i + 1, new_mask, changed);
        }

        if (!changed) {
            // 枚举把 s[i] 改成 a,b,c,...,z
            for (int j = 0; j < 26; j++) {
                new_mask = mask | (1 << j);
                if (popcount((uint32_t) new_mask) > k) {
                    // 分割出一个子串，这个子串的最后一个字母在 i-1
                    // j 作为下一段的第一个字母，也就是 1<<j 作为下一段的 mask 的初始值
                    res = max(res, dfs(i + 1, 1 << j, true) + 1);
                } else { // 不分割
                    res = max(res, dfs(i + 1, new_mask, true));
                }
            }
        }

        return memo[args] = res; // 记忆化
    };
    return dfs(0, 0, false);
}