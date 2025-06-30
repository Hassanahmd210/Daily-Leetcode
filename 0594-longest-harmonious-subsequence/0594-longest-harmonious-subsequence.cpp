class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            bool checked = false;

            for (int k = 0; k < i; k++) {
                if (nums[k] == nums[i]) {
                    checked = true;
                    break;
                }
            }
            
            if (checked) continue;

            int c1 = 0, c2 = 0;

            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == nums[i]) {
                    c1++;
                }
                else if (nums[j] == nums[i] + 1) {
                    c2++;
                }
            }

            if (c2 > 0 && c1 + c2 > ans) {
                ans = c1 + c2;
            }
        }

        return ans;
    }
};