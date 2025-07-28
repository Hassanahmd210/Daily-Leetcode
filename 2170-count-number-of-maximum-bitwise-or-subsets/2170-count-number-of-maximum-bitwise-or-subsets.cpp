class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            mx |= nums[i];
        }

        int total = 1 << n;

        for(int mask = 1; mask < total; mask++) { 
            int cur = 0;
            for(int j = 0; j < n; j++) {
                if(mask & (1 << j)) cur |= nums[j];
            }
            if(cur == mx) {
                ans++;
            }
        }
        return ans;
    }
};
