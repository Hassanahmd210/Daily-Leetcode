class Solution {
public:
    static int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        auto& s = startTime;
        auto& e = endTime;
        int n = s.size(), T = eventTime, K = k, b = 0;
        
        for (int i = 0; i < K; i++)
            b += e[i] - s[i];
        
        if (n == K) 
            return T - b;
        
        int m = s[K] - b;
        for (int l = 0, r = K; r < n; l++, r++) {

            b += (e[r] - s[r]) - (e[l] - s[l]);

            int nxt = (r == n - 1 ? T : s[r + 1]);
            
            m = max(m, nxt - e[l] - b);
        }
        
        return m;
    }
};