class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int mx = num, mn = num;

        for (char x : s) {
            for (char y = '0'; y <= '9'; y++) {
                if (x != y) {
                    string t = s;
                    for (char &c : t) {
                        if (c == x) c = y;
                    }
                    if (t[0] != '0') mx = max(mx, stoi(t));
                }
            }
        }

        for (char x : s) {
            for (char y = '0'; y <= '9'; y++) {
                if (x != y) {
                    string t = s;
                    for (char &c : t) {
                        if (c == x) c = y;
                    }
                    if (t[0] != '0') mn = min(mn, stoi(t));
                }
            }
        }

        return mx - mn;
    }
};

