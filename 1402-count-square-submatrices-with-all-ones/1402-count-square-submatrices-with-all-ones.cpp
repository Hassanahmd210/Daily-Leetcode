class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        int res = 0;
        
        for (int s = 1; s <= min(r, c); s++) {
            for (int i = 0; i <= r - s; i++) {
                for (int j = 0; j <= c - s; j++) {
                    bool ok = true;
                    for (int x = i; x < i + s; x++) {
                        for (int y = j; y < j + s; y++) {
                            if (mat[x][y] == 0) {
                                ok = false;
                                break;
                            }
                        }
                        if (!ok) break;
                    }
                    if (ok) res++;
                }
            }
        }
        
        return res;
    }
};
