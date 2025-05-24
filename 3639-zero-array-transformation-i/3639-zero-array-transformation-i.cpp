class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            diff[l] += 1;
            if (r + 1 < n) {
                diff[r + 1] -= 1;
            }
        }

        int cover = 0;
        for (int i = 0; i < n; i++) {
            cover += diff[i];
            if (cover < nums[i]) {
                return false;
            }
        }

        return true;
    }
};
