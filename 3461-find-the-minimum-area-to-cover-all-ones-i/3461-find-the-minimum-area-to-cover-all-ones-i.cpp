class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int min_r = n, max_r = -1;
        int min_c = m, max_c = -1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    if (i < min_r) min_r = i;
                    if (i > max_r) max_r = i;
                    if (j < min_c) min_c = j;
                    if (j > max_c) max_c = j;
                }
            }
        }
        
        int h = max_r - min_r + 1;
        int w = max_c - min_c + 1;
        
        return h * w;
    }
};