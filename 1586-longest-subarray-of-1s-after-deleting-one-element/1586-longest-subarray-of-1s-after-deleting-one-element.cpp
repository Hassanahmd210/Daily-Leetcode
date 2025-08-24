class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0, count = 0, maxLen = 0;
        
        while (r < nums.size()) {
            if (nums[r] == 0) count++;
            
            while (count > 1) {
                if (nums[l] == 0) count--;
                l++;
            }
            
            maxLen = max(maxLen, r - l);
            r++;
        }
        
        return maxLen;
    }
};
