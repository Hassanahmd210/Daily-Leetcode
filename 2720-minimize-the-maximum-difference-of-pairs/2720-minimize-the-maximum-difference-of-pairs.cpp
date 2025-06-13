class Solution {
public:
    int minimizeMax(vector<int>& a, int p) {
        sort(a.begin(), a.end());
        int n = a.size();
        int lo = 0, hi = a[n - 1] - a[0], ans = hi;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int c = 0;
            for (int i = 0; i < n - 1; i++) {
                if (a[i + 1] - a[i] <= mid) {
                    c++;
                    i++;
                }
            }
            if (c >= p) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};