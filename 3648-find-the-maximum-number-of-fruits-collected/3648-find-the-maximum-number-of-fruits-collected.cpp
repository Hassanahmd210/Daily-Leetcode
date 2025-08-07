using ll = long long;

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        ll n = fruits.size();
        ll totalFruits = 0;

        for (ll i = 0; i < n; i++) {
            totalFruits += fruits[i][i];
            fruits[i][i] = 0;
        }

        vector<vector<ll>> dp(n, vector<ll>(n, 0));

        dp[0][n - 1] = fruits[0][n - 1];
        dp[n - 1][0] = fruits[n - 1][0];

        for (ll i = 1; i < n - 1; i++) {
            ll start_j = n - 1;
            ll end_j = (i >= n / 2) ? n - (n - i - 1) : n - i - 1;

            for (ll j = start_j; j >= end_j; j--) {
                ll moveTopLeft = (i - 1 >= 0 && j - 1 >= 0) ? dp[i - 1][j - 1] : 0;
                ll moveTop = (i - 1 >= 0) ? dp[i - 1][j] : 0;
                ll moveTopRight = (i - 1 >= 0 && j + 1 < n) ? dp[i - 1][j + 1] : 0;

                dp[i][j] = max({moveTopLeft, moveTop, moveTopRight}) + fruits[i][j];

                ll moveJL = (j - 1 >= 0 && i - 1 >= 0) ? dp[j - 1][i - 1] : 0;
                ll moveJ = (i - 1 >= 0) ? dp[j][i - 1] : 0;
                ll moveJR = (j + 1 < n && i - 1 >= 0) ? dp[j + 1][i - 1] : 0;

                dp[j][i] = max({moveJL, moveJ, moveJR}) + fruits[j][i];
            }
        }

        totalFruits += dp[n - 2][n - 1] + dp[n - 1][n - 2];

        return (int)totalFruits;
    }
};
