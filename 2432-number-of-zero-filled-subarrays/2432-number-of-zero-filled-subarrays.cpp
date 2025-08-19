class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0, c = 0;
        for (int x : nums) {
            if (x == 0) {
                c++;
                res += c;
            } else {
                c = 0;
            }
        }
        return res;
    }
};
