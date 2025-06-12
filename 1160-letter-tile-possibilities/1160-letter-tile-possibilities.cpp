class Solution {
public:
    void bt(string &t, vector<bool> &u, unordered_set<string> &s, string c) {
        if (!c.empty()) s.insert(c);
        for (int i = 0; i < t.size(); i++) {
            if (u[i]) continue;
            u[i] = true;
            bt(t, u, s, c + t[i]);
            u[i] = false;
        }
    }

    int numTilePossibilities(string t) {
        unordered_set<string> s;
        vector<bool> u(t.size(), false);
        bt(t, u, s, "");
        return s.size();
    }
};