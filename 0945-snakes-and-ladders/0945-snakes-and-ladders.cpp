class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> moves(n * n + 1, -1);
        bool leftToRight = true;
        int num = 1;

        for (int i = n - 1; i >= 0; --i) {
            if (!leftToRight) reverse(board[i].begin(), board[i].end());
            for (int j = 0; j < n; ++j) {
                moves[num++] = board[i][j] == -1 ? num : board[i][j];
            }
            leftToRight = !leftToRight;
        }

        queue<pair<int, int>> q;
        q.push({1, 0});
        unordered_map<int, bool> visited;
        visited[1] = true;

        while (!q.empty()) {
            auto [pos, rolls] = q.front();
            q.pop();

            if (pos == n * n) return rolls;

            for (int dice = 1; dice <= 6; ++dice) {
                int nextPos = pos + dice;
                if (nextPos <= n * n && !visited[nextPos]) {
                    visited[nextPos] = true;
                    q.push({moves[nextPos], rolls + 1});
                }
            }
        }

        return -1; 
    }
};