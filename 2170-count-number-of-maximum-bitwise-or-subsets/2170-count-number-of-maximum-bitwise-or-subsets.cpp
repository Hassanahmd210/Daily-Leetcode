class Solution {
public:
    int maxOr;
    int cnt;

    void bt(vector<int>& nums, int i, int orr) {
        if(i == nums.size()) {
            if(orr == maxOr) cnt++;
            return;
        }
        bt(nums, i + 1, orr);
        bt(nums, i + 1, orr | nums[i]);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        maxOr = 0;
        cnt = 0;
        for(int x : nums) maxOr |= x;
        bt(nums, 0, 0);
        return cnt;
    }
};
