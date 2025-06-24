class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& a, int key, int k) {

        int n = a.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {

            for (int j = max(0, i - k); j <= min(n - 1, i + k); j++) {

                if (a[j] == key) {

                    ans.push_back(i);

                    break;
                }
            }
        }
        
        return ans;
    }
};