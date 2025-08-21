#include <vector>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> left(r, vector<int>(c, 0));
        int ans = 0;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 1) {
                    left[i][j] = (j > 0 ? left[i][j - 1] : 0) + 1;
                }
            }
        }
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 0) continue;
                int mn = left[i][j];
                ans += mn;
                for (int k = i - 1; k >= 0; k--) {
                    if (left[k][j] == 0) break;
                    mn = min(mn, left[k][j]);
                    ans += mn;
                }
            }
        }
        
        return ans;
    }
};