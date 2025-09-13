class Solution {
public:
    int maxFreqSum(string s) {
        int f[26] = {0};
        for (char x : s) f[x - 'a']++;

        string v = "aeiou";
        int mv = 0, mc = 0;

        for (int i = 0; i < 26; i++) {
            char x = 'a' + i;
            
            if (v.find(x) != -1) {
                if (f[i] > mv) mv = f[i];
            } 

            else {
                if (f[i] > mc) mc = f[i];
            }
        }

        return mv + mc;
    }
};