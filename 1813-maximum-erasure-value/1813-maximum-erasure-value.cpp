class Solution {
public:
    int maximumUniqueSubarray(vector<int>& a) {
        int n = a.size();
        int l = 0, r = 0,s = 0, m = 0;
        set<int> x;

        while (r < n) {

            while (x.count(a[r])) {
                
                x.erase(a[l]);
                s -= a[l];
                l++;
            }

            x.insert(a[r]);
            s += a[r];
            m = max(m, s);
            r++;
        }

        return m;
    }
};