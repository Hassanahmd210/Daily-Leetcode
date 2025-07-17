class Solution {
public:
    int maximumLength(vector<int>& a, int k) {
        int n = a.size(), ans = 0;
        vector<int> rem(n);
        
        for (int i = 0; i < n; ++i)
            rem[i] = a[i] % k;
        
        vector<int> best(k);
        for (int c = 0; c < k; ++c) {
            fill(best.begin(), best.end(), 0);
            
            for (int i = 0; i < n; ++i) {
                int need = (c - rem[i] + k) % k;
                int cur  = best[need] + 1;
                best[ rem[i] ] = max(best[ rem[i] ], cur);
                ans = max(ans, cur);
            }
        }
        
        return ans;
    }
};