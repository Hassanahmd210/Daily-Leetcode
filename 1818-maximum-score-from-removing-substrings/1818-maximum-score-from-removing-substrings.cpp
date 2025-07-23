class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;

        auto rem = [](string s, char a, char b, int p) {
            string t = "";
            int sc = 0;

            for (char ch : s) {
                if (!t.empty() && t.back() == a && ch == b) {
                    t.pop_back();
                    sc += p;
                } 
                else {
                    t += ch;
                }
            }

            return make_pair(t, sc);
        };

        if (x > y) {
            auto [s1, p1] = rem(s, 'a', 'b', x);
            auto [s2, p2] = rem(s1, 'b', 'a', y);
            ans = p1 + p2;
        } 
        else {
            auto [s1, p1] = rem(s, 'b', 'a', y);
            auto [s2, p2] = rem(s1, 'a', 'b', x);
            ans = p1 + p2;
        }

        return ans;
    }
};