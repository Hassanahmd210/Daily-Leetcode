class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int x = 0;
        for (int i = 0; i < nums.size(); i++) {
            x ^= nums[i]; 
        }

        int d = x ^ k; 
        int flips = 0;

        for (int i = 0; i < 32; i++){
            if ((d >> i) & 1) {
                flips++;
            }
        }
        return flips;
    }
};