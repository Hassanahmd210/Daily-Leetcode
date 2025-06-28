class Solution {
public:
    vector<int> maxSubsequence(vector<int>& a, int k) {
        vector<pair<int, int>> v;
        int n = a.size();

        for (int i = 0; i < n; i++) {
            v.push_back({a[i], i});
        }

        sort(v.begin(), v.end(), greater<>());
        vector<int> idx;

        for (int i = 0; i < k; i++) {
            idx.push_back(v[i].second);
        }

        sort(idx.begin(), idx.end());
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(a[idx[i]]);
        }

        return ans;
    }
};