class Solution {
public:
    int peopleAwareOfSecret(int n, int d, int f) {
        int m = 1e9 + 7;
        vector<int> a(n + 1, 0);
        a[1] = 1;
        int s = 0;

        for (int i = 2; i <= n; i++) {
            if (i - d >= 1)
                s = (s + a[i - d]) % m;
            if (i - f >= 1)
                s = (s - a[i - f] + m) % m;
            a[i] = s;
        }

        int t = 0;
        for (int i = n - f + 1; i <= n; i++) {
            t = (t + a[i]) % m;
        }

        return t;
    }
};