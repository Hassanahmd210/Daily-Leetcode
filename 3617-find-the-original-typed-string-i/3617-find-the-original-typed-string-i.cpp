class Solution {
public:
    int possibleStringCount(string word) {
        int res = 1; 

        for(int i = 0; i < word.length();) {
            int j = i;

            while(j < word.length() && word[j] == word[i]) {
                j++;
            }

            int count = j - i;
            
            if(count > 1) {
                res += count - 1;
            }
            i = j;
        }
        return res;
    }
};