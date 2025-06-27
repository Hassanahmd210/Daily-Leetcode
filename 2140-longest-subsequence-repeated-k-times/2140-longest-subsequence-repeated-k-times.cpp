class Solution {
    string s;
    int n, k;
    vector<vector<int>> nxt;
    vector<int> chs;
    string res;

    bool ok(const string &t) {
        int p = 0;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < (int)t.size(); j++) {
                int c = t[j] - 'a';
                if (p > n || nxt[p][c] == n) {
                    return false;
                }
                p = nxt[p][c] + 1;
            }
        }
        return true;
    }

    void dfs(string t) {
        if (t.size() > res.size() || (t.size() == res.size() && t > res)){
            res = t;
        } 
        for (int i = 0; i < (int)chs.size(); i++) {
            char c = 'a' + chs[i];
            string u = t + c;
            if (ok(u)) dfs(u);
        }
    }

public:
    string longestSubsequenceRepeatedK(string str, int kk) {
        s = str; k = kk; n = s.size();
        nxt.assign(n + 1, vector<int>(26, n));

        for (int i = n - 1; i >= 0; i--) {
            for (int c = 0; c < 26; c++){
                nxt[i][c] = nxt[i + 1][c];
            }
            nxt[i][s[i] - 'a'] = i;
        }

        int f[26] = {0};

        for (int i = 0; i < n; i++){
            f[s[i] - 'a']++;
        }
        for (int c = 0; c < 26; c++){
            if (f[c] >= k){
                chs.push_back(c);
            }
        }

        sort(chs.begin(), chs.end(), greater<int>());
        dfs("");
        
        return res;
    }
};