class Solution {
public:
    int maxCandies(vector<int>& st, vector<int>& can, vector<vector<int>>& ky, vector<vector<int>>& cb, vector<int>& ini) {
        int n = st.size();
        vector<bool> have(n, false), used(n, false), key(n, false);
        queue<int> q;
        int tot = 0;
        
        for (int b : ini) {
            have[b] = true;
            if (st[b] == 1)
                q.push(b);
        }
        
        while (!q.empty()) {
            int b = q.front();
            q.pop();
            if (used[b])
                continue;
            used[b] = true;
            tot += can[b];
            for (int k : ky[b]) {
                if (!key[k]) {
                    key[k] = true;
                    if (have[k] && st[k] == 0) {
                        st[k] = 1;
                        q.push(k);
                    }
                }
            }
            for (int nb : cb[b]) {
                if (!have[nb]) {
                    have[nb] = true;
                    if (st[nb] == 1 || key[nb])
                        q.push(nb);
                }
            }
        }
        
        return tot;
    }
};

