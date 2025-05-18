class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string num;
        
        for (int i = 1; i <= n + 1; i++) {
            num += (char)('0' + i);
        }

        do {
            bool valid = true;
            for (int i = 0; i < n; i++) {
                if ((pattern[i] == 'I' && num[i] >= num[i + 1]) || 
                    (pattern[i] == 'D' && num[i] <= num[i + 1])) {
                    valid = false;
                    break;
                }
            }
            if (valid) return num;
        } while (next_permutation(num.begin(), num.end()));

        return ""; 
    }
};
