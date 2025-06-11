class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> ans;
        vector<int> cur;
        
        for (int i = 1; i <= k; i++) {
            cur.push_back(i);
        }
        
        while (true) {
            ans.push_back(cur);
            int i = k - 1;
            while (i >= 0 && cur[i] == n - k + 1 + i) {
                --i;
            }
            if (i < 0){
                break;
            }
            cur[i]++;

            for (int j = i + 1; j < k; j++) {
                cur[j] = cur[j - 1] + 1;
            }
        }
        
        return ans;
    }
};