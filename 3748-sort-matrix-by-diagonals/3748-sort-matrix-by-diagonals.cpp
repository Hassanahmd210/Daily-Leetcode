class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& g) {
        int n = g.size();
        unordered_map<int, vector<int>> diag;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                diag[i - j].push_back(g[i][j]);
            }
        }
        for (auto& [d, v] : diag) {
            if (d >= 0) sort(v.begin(), v.end(), greater<int>());
            else       sort(v.begin(), v.end());
        }
        unordered_map<int, int> ptr;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int d = i - j;
                g[i][j] = diag[d][ptr[d]++];
            }
        }
        return g;
    }
};