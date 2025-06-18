class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& a, int k) {

        sort(a.begin(), a.end());
        vector<vector<int>> res;

        for (int i = 0; i < a.size(); i += 3) {

            if (i + 2 < a.size() && a[i + 2] - a[i] <= k) {

                res.push_back({a[i], a[i + 1], a[i + 2]});

            }
             else {

                return {};
                
            }
        }

        return res;
    }
};