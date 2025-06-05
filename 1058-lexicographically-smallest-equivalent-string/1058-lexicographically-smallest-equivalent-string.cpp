class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        char map[26];

        for (int i = 0; i < 26; i++)
            map[i] = 'a' + i;

        for (int i = 0; i < s1.size(); i++) {
            char x = map[s1[i] - 'a'];
            char y = map[s2[i] - 'a'];
            char small = (x < y) ? x : y;

            for (int j = 0; j < 26; j++) {
                if (map[j] == x || map[j] == y)
                    map[j] = small;
            }
        }

        for (int i = 0; i < baseStr.size(); i++) {
            baseStr[i] = map[baseStr[i] - 'a'];
        }

        return baseStr;
    }
};