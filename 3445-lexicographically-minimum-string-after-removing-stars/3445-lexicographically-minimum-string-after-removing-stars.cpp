class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> b(26);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                int j = 0;
                while (b[j].empty()) ++j;
                s[b[j].back()] = ' ';
                b[j].pop_back();
                s[i] = ' ';
            } else {
                b[s[i] - 'a'].push_back(i);
            }
        }
        string r;
        for (char c : s) {
            if (c != ' ') r += c;
        }
        return r;
    }
};
