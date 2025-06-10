class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> f;
        for (char c : s) {
            f[c]++;
        }
        
        int maxO = INT_MIN;
        int minE = INT_MAX;

          for (char c = 'a'; c <= 'z'; c++) {

            if (f[c] % 2) {
                maxO = max(maxO, f[c]);
            }
            else if (f[c]) {
                minE = min(minE, f[c]);
            }
        }        
        return maxO - minE;
    }
};