#include <vector>
using namespace std;

class Solution {
    vector<vector<double>> dp;
    
    double go(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        if (dp[a][b] >= 0) return dp[a][b];
        return dp[a][b] = 0.25 * (
            go(a - 4, b) +
            go(a - 3, b - 1) +
            go(a - 2, b - 2) +
            go(a - 1, b - 3)
        );
    }

public:
    double soupServings(int n) {
        if (n > 4800) return 1.0;
        int u = (n + 24) / 25;
        dp.assign(u + 1, vector<double>(u + 1, -1));
        return go(u, u);
    }
};