class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {

        int n = a.size();
        vector<vector<int>> res;
        sort(a.begin(), a.end());

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && a[i] == a[i - 1]) 
                continue;

            int l = i + 1, r = n - 1;

            while (l < r) {

                int s = a[i] + a[l] + a[r];

                if (s == 0) {
                    res.push_back({a[i], a[l], a[r]});
                    l++; r--;
                    while (l < r && a[l] == a[l - 1]) l++;
                    while (l < r && a[r] == a[r + 1]) r--;
                } 
                
                else if (s < 0) l++;
                else r--;
            }
        }
        return res;
    }
};