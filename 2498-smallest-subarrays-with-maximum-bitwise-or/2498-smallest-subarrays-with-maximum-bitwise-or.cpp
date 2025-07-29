class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, INT_MAX);

        for (int i = 0; i < n; ++i) {
            int bo = nums[i];
            ans[i] = 1;
            int j = i - 1;

            while (j >= 0 && (nums[j] | bo) != nums[j]) {
                ans[j] = i - j + 1;
                nums[j] |= bo;
                --j;
            }
        }
        return ans;
    }
};