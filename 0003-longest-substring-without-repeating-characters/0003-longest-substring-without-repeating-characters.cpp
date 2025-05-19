class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        int maxLength = 0;
        int length;

        for (int i = 0; i < n; i++) {

            vector<int> hash(256, 0); // Hash array for visited characters

            for (int j = i; j < n; j++) {

                if (hash[s[j]] == 1) {
                break; // Character already seen
                } 
                hash[s[j]] = 1;
                length = j-i+1;
                maxLength = max(maxLength, length);
            }
        }
        return maxLength;
    }
};