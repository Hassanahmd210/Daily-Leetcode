class Solution {
public:
    int partitionArray(vector<int>& a, int k) {

        sort(a.begin(), a.end());
        int n = a.size();
        int cnt = 1;
        int minVal = a[0];

        for (int i = 1; i < n; i++) {
            
            if (a[i] - minVal > k) {
                cnt++;
                minVal = a[i];
            }
        }
        return cnt;
    }
};