class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& f, int s, int k) {
        int n = f.size();
        int   l = 0, sum = 0, ans = 0;

        for(int r = 0; r < n; ++r) {
            sum += f[r][1];
            
            while(l <= r) {
                int d = min(abs(s - f[l][0]) + f[r][0] - f[l][0], abs(s - f[r][0]) + f[r][0] - f[l][0]);
                if(d <= k) break;
                sum -= f[l][1];
                ++l;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
