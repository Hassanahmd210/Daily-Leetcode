class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        int ans = 0;
        char cand[4][2] = { {'N', 'E'}, {'N', 'W'}, {'S', 'E'}, {'S', 'W'} };

        for (int d = 0; d < 4; d++) {
            char c1 = cand[d][0];
            char c2 = cand[d][1];
            int sum = 0;
            int bad = 0;
            int mx = 0;

            for (int i = 0; i < n; i++) {

                char ch = s[i];

                if (ch == c1 || ch == c2) {
                    sum++;
                }
                else {
                    sum--;
                    bad++;
                }
                
                int cur = sum + 2 * (bad < k ? bad : k);
                if (cur > mx) {
                    mx = cur;
                }
            }
            if (mx > ans) {
                ans = mx;
            }
        }
        
        return ans;
    }
};