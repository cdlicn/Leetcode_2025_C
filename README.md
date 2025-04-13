# -Leetcode_2025_C
2025力扣做题记录 C/C++

```c++
// 快速幂 求余
const int MOD = 1'000'000'007;

long long qpow(long long x, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
return res;
}
```