class Solution {
public:
    int minMaxDifference(int n) {
        string s = to_string(n), mx = s, mn = s;

        char r1 = ' ';
        for (char c : s) {
            if (c != '9') {
                r1 = c;
                break;
            }
        }
        if (r1 != ' ') {
            for (char &c : mx) {
                if (c == r1) c = '9';
            }
        }

        char r2 = s[0];
        for (char &c : mn) {
            if (c == r2) c = '0';
        }

        return stoi(mx) - stoi(mn);
    }
};