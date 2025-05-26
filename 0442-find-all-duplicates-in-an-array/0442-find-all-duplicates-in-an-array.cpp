class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        int k = nums.size() + 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 1 && nums[i] <= nums.size()) {
                nums[nums[i] - 1] += k;
            } else {
                if (nums[i] > 2 * k) {
                    nums[nums[i] - 1 - 2 * k] += k;
                } else {
                    nums[nums[i] - 1 - k] += k;
                }
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 2 * k) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};