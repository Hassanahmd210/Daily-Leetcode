
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& q) {
        long long mod = 1e9 + 7;
        vector<int> p;
        for (int i = 0; n > 0; i++) {
            if (n & (1 << i)) {
                p.push_back(1 << i);
                n -= (1 << i);
                i = -1;
            }
        }
        sort(p.begin(), p.end());
        vector<int> ans;
        for (auto &x : q) {
            long long v = 1;
            for (int i = x[0]; i <= x[1]; i++) {
                v = (v * p[i]) % mod;
            }
            ans.push_back(v);
        }
        return ans;
    }
};
