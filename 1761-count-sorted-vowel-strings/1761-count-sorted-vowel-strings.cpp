class Solution {
public:
    int countVowelStrings(int n) {
        
        long result = 1;
        for (int i = 1; i <= 4; ++i) {
            result = result * (n + i) / i;
        }
        return result;
    }
};
