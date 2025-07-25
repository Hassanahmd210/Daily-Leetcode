class Solution {
public:
    int maxSum(vector<int>& a) {

        int n = a.size();
        int maxEl = a[0];
        unordered_set<int> seen;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int v = a[i];

            if (v > maxEl) 
                maxEl = v;
                
            if (v > 0 && !seen.count(v)) {
                seen.insert(v);
                sum += v;
            }
        }

        return sum > 0 ? sum : maxEl;
    }
};