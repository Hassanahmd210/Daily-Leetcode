class Solution {
public:
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        gen(0, 0, "", res, n);
        return res;
    }

    void gen(int o, int c, string cur, vector<string>& res, int n) {
        // If the string is complete
        if (cur.length() == n * 2) {
            res.push_back(cur);
            return;
        }

        // Add open bracket if available
        if (o < n) {
            gen(o + 1, c, cur + "(", res, n);
        }

        // Add close bracket if valid
        if (c < o) {
            gen(o, c + 1, cur + ")", res, n);
        }
    }

};
