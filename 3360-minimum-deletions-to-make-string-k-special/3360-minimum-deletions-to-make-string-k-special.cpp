class Solution {
public:
    int minimumDeletions(string word, int k) {
        int c[26] = {0};

        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            c[idx]++;
        }

        int a[26], t = 0;

        for (int i = 0; i < 26; i++) {
            if (c[i] > 0) {
                a[t] = c[i];
                t++;
            }
        }

        int r = word.size();

        for (int p = 0; p < t; p++) {
            int x = a[p];
            int d = 0;
            
            for (int q = 0; q < t; q++) {
                int y = a[q];
                if (y < x) {
                    d += y;
                }
                else if (y > x + k) {
                    d += y - x - k;
                }
            }
            if (d < r) {
                r = d;
            }
        }
        return r;
    }
};