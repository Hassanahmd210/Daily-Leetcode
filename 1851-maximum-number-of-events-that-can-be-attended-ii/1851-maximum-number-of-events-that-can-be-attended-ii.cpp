class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());  

        vector<int> s(n), e(n), v(n), nxt(n);
        for (int i = 0; i < n; i++) {
            s[i] = events[i][0];
            e[i] = events[i][1];
            v[i] = events[i][2];
        }

        for (int i = 0; i < n; i++) {
            int lo = i + 1, hi = n;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (s[mid] > e[i]) hi = mid;
                else lo = mid + 1;
            }
            nxt[i] = lo;
        }

        vector<long long> prev(n+1), cur(n+1);
        
        for (int j = 1; j <= k; j++) {
            for (int i = n - 1; i >= 0; i--) {
                long long skip = cur[i+1];
                long long take = v[i] + prev[nxt[i]];
                cur[i] = max(skip, take);
            }
            prev.swap(cur);
        }

        return (int)prev[0];
    }
};