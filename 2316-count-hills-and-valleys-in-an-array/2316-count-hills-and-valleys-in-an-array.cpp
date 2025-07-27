class Solution {
public:
    int countHillValley(vector<int>& a) {
        int n = a.size();
        int c = 0;

        for (int i = 1; i < n - 1; i++) {
            if (a[i] == a[i - 1]) {
                continue;
            }

            int l = i - 1;
            while (l >= 0 && a[l] == a[i]) {
                l--;
            }

            int r = i + 1;
            while (r < n && a[r] == a[i]) {
                r++;
            }

            if (l >= 0 && r < n) {
                if (a[i] > a[l] && a[i] > a[r]) {
                    c++;
                } else if (a[i] < a[l] && a[i] < a[r]) {
                    c++;
                }
            }
        }

        return c;
    }
};