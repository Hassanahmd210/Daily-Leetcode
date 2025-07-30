
class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int m = 0;
        for (int x : a) 
            if (x > m) 
                m = x;

        int res = 0, cur = 0;

        for (int x : a) {
            if (x == m) {
                cur++;

                if (cur > res) 
                    res = cur;
            } 
            
            else {
                cur = 0;
            }
        }
        return res;
    }
};