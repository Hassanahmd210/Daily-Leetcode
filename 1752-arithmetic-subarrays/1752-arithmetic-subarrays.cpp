class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        int m = l.size();

        for (int i = 0; i < m; i++) {

            vector<int> sub(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(sub.begin(), sub.end());
            int d = sub[1] - sub[0];
            bool ok = true;

            for (int j = 2; j < sub.size(); j++) { 
                if (sub[j] - sub[j - 1] != d) {
                    ok = false;
                    break;
                }
            }
            
            ans.push_back(ok);
        }
        return ans;
    }
};