#include <iostream>
#include <vector>

using namespace std;
using int64 = long long;

const int MOD = 1'000'000'007;

int64 modPow(int64 base, int exp) {
    int64 res = 1;
    while (exp) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

int64 modInv(int x) {
    if (x == 1) return 1;
    return (MOD - MOD / x) * modInv(MOD % x) % MOD;
}

int64 comb(int n, int r) {
    if (r < 0 || r > n) return 0;
    int64 res = 1;
    vector<int> inv(r + 1, 1);

    for (int i = 2; i <= r; ++i) {
        inv[i] = int64(MOD - MOD / i) * inv[MOD % i] % MOD;
    }

    for (int i = 1; i <= r; ++i) {
        res = res * (n - r + i) % MOD;
        res = res * inv[i] % MOD;
    }
    return res;
}

class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        int gaps = n - 1;
        if (k > gaps) return 0;

        int r = min(k, gaps - k);
        int64 choose = comb(gaps, r);
        int64 diffWays = modPow(m - 1, gaps - k);
        int64 ans = int64(m) * choose % MOD * diffWays % MOD;

        return (int)ans;
    }
};
