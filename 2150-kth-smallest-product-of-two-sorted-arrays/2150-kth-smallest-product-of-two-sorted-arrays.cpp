class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        auto fdiv = [&](long long a, long long b) {
            long long q = a / b, r = a % b;
            if (r != 0 && ((a > 0) != (b > 0))) q--;
            return q;
        };

        auto cdiv = [&](long long a, long long b) {
            long long q = a / b, r = a % b;
            if (r != 0 && ((a > 0) == (b > 0))) q++;
            return q;
        };

        auto cntLE = [&](long long m) {
            long long cnt = 0;

            for (int i = 0; i < n1; i++) {
                long long x = nums1[i];
                
                if (x > 0) {
                    long long t = fdiv(m, x);
                    int l = upper_bound(nums2.begin(), nums2.end(), t) - nums2.begin();
                    cnt += l;
                } 
                else if (x == 0) {
                    if (m >= 0) cnt += n2;
                } 
                else {
                    long long t = cdiv(m, x);
                    int l = lower_bound(nums2.begin(), nums2.end(), t) - nums2.begin();
                    cnt += (n2 - l);
                }
            }
            return cnt;
        };

        long long lo = -100000LL * 100000, hi = 100000LL * 100000;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (cntLE(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};