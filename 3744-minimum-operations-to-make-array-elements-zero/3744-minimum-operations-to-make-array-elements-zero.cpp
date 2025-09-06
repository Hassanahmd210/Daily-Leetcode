class Solution {
public:
    long long minOperations(vector<vector<int>>& q) {
        long long ans = 0;
        for (auto &p : q) {
            long long l = p[0], r = p[1];
            long long sum = 0, mx = 0;
            long long base = 1;
            for (long long k = 1; base <= r; ++k) {
                long long lo = base, hi = base * 4 - 1;
                if (hi < l) { base *= 4; continue; }
                if (lo > r) break;
                long long a = max(l, lo), b = min(r, hi);
                long long cnt = b - a + 1;
                sum += cnt * k;
                mx = max(mx, k);
                base *= 4;
            }
            ans += max(mx, (sum + 1) / 2);
        }
        return ans;
    }
};