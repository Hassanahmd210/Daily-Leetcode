class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        const int INF = 1000000000, NEG_INF = -1000000000;
        int res = NEG_INF;
        bool found = false;
        // Try every ordered pair (da, db) where da != db.
        for (int da = 0; da < 5; ++da) {
            for (int db = 0; db < 5; ++db) {
                if (da == db) continue;
                // Build prefix counts for digit da and db.
                vector<int> pa(n+1, 0), pb(n+1, 0), d(n+1, 0);
                for (int i = 0; i < n; i++) {
                    pa[i+1] = pa[i] + ((s[i]-'0') == da);
                    pb[i+1] = pb[i] + ((s[i]-'0') == db);
                    d[i+1] = pa[i+1] - pb[i+1];
                }
                // BIT arrays for 4 buckets, indexing by pb values.
                int sz = n+1;
                vector<vector<int>> bit(4, vector<int>(sz+1, INF));
                auto upd = [&](int idx, int pos, int val) {
                    for (++pos; pos <= sz; pos += pos & -pos)
                        bit[idx][pos] = min(bit[idx][pos], val);
                };
                auto qry = [&](int idx, int pos) -> int {
                    int ans = INF;
                    for (++pos; pos; pos -= pos & -pos)
                        ans = min(ans, bit[idx][pos]);
                    return ans;
                };
                int best = NEG_INF;
                bool valid = false;
                int p = 0;
                // r goes from k to n (r is our prefix index; substring is [l, r)).
                for (int r = k; r <= n; r++) {
                    while(p <= r - k) {
                        // Bucket determined by (pa[l] mod 2, pb[l] mod 2).
                        int bid = ((pa[p] & 1) << 1) | (pb[p] & 1);
                        upd(bid, pb[p], d[p]);
                        p++;
                    }
                    // We need: (pa[r]-pa[l]) odd and (pb[r]-pb[l]) even with pb[r] > pb[l].
                    int bidQ = ((1 - (pa[r] & 1)) << 1) | (pb[r] & 1);
                    int lim = pb[r] - 1;
                    if (lim >= 0) {
                        int cand = qry(bidQ, lim);
                        if (cand < INF) { 
                            best = max(best, d[r] - cand);
                            valid = true;
                        }
                    }
                }
                if (valid) {
                    res = max(res, best);
                    found = true;
                }
            }
        }
        return found ? res : -1;
    }
};