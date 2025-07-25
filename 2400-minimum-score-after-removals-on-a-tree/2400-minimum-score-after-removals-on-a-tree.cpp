class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> parent(n, -1), sx(n, 0), tin(n), tout(n);
        int timer = 0;

        // DFS to compute subtree XORs, parents, and in/out times
        function<void(int, int)> dfs = [&](int u, int p) {
            tin[u] = ++timer;
            sx[u] = nums[u];
            parent[u] = p;
            for (int v : g[u]) {
                if (v != p) {
                    dfs(v, u);
                    sx[u] ^= sx[v];
                }
            }
            tout[u] = ++timer;
        };

        dfs(0, -1);
        int total = sx[0];
        vector<pair<int, int>> edges2; // edges as parent->child
        for (int i = 1; i < n; ++i) {
            edges2.push_back({parent[i], i});
        }

        // Check if u is ancestor of v
        auto is_anc = [&](int u, int v) {
            return tin[u] <= tin[v] && tout[u] >= tout[v];
        };

        int res = INT_MAX, m = edges2.size();
        for (int i = 0; i < m; ++i) {
            for (int j = i+1; j < m; ++j) {
                int a = edges2[i].second, b = edges2[j].second;
                int x, y, z;
                if (is_anc(a, b)) {
                    x = sx[b];
                    y = sx[a] ^ sx[b];
                    z = total ^ sx[a];
                }
                else if (is_anc(b, a)) {
                    x = sx[a];
                    y = sx[b] ^ sx[a];
                    z = total ^ sx[b];
                }
                else {
                    x = sx[a];
                    y = sx[b];
                    z = total ^ sx[a] ^ sx[b];
                }
                int mx = max({x, y, z});
                int mn = min({x, y, z});
                res = min(res, mx - mn);
            }
        }
        return res;
    }
};
