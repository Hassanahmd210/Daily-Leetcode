class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        int i, z = 0, o = 0;
        long long v = 0, p = 1;

        for (i = 0; i < n; i++) {
            if (s[i] == '0') {
                z++;
            }
        }

        for (i = n - 1; i >= 0; i--) {

            if (s[i] == '1') {

                if (p <= k && v + p <= k) {
                    v = v + p;
                    o = o + 1;
                }
            }

            p = p * 2;
            
            if (p > k) {
                break;
            }
        }

        return z + o;
    }
};