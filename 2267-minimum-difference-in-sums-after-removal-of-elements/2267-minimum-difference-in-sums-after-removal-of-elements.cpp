class Solution {
public:
    long long minimumDifference(vector<int>& a) {
        int sz = a.size();
        int n = sz / 3;
        long long ans = LLONG_MAX;

        for (int i = 0; i <= sz - n; i++) {
            vector<int> left;
            for (int j = 0; j < sz; j++) {
                if (j < i || j >= i + n) {
                    left.push_back(a[j]);
                }
            }

            long long s1 = 0, s2 = 0;
            for (int j = 0; j < n; j++) {
                s1 += left[j];
            }
            for (int j = n; j < 2 * n; j++) {
                s2 += left[j];
            }

            long long diff = s1 - s2;
            ans = min(ans, diff);
        }

        return ans;
    }
};