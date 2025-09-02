class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
        int n = p.size();
        int c = 0;
        for (int i = 0; i < n; i++) {
            int x1 = p[i][0];
            int y1 = p[i][1];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int x2 = p[j][0];
                int y2 = p[j][1];
                if (x1 > x2 || y1 < y2) continue;
                bool ok = true;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    int x = p[k][0];
                    int y = p[k][1];
                    if (x >= x1 && x <= x2 && y >= y2 && y <= y1) {
                        ok = false;
                        break;
                    }
                }
                if (ok) c++;
            }
        }
        return c;
    }
};