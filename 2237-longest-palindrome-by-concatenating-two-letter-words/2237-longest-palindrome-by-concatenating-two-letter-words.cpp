class Solution {
public:
    int longestPalindrome(vector<string>& w) {
        unordered_map<string, int> mp;
        int res = 0;
        bool mid = false;

        for (int i = 0; i < w.size(); i++) {
            mp[w[i]]++;
        }

        for (auto it = mp.begin(); it != mp.end(); ++it) {
            string s = it->first;
            int cnt = it->second;

            if (s[0] == s[1]) {
                res += (cnt / 2) * 4;
                if (cnt % 2 == 1) {
                    mid = true;
                }
            } else {
                string rev = "";
                rev += s[1];
                rev += s[0];

                if (mp.find(rev) != mp.end()) {
                    int pairs = min(cnt, mp[rev]);
                    res += pairs * 4;
                    mp[rev] = 0;
                    mp[s] = 0;
                }
            }
        }

        if (mid) {
            res += 2;
        }

        return res;
    }
};
