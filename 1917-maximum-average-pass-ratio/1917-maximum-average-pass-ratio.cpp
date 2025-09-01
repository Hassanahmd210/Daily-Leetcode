class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& a, int k) {
        priority_queue<pair<double, pair<int, int>>> pq;

        for (auto& x : a) {
            int p = x[0], t = x[1];
            double gain = ((double)(p + 1) / (t + 1)) - ((double)p / t);
            pq.push({gain, {p, t}});
        }

        while (k--) {
            auto top = pq.top(); pq.pop();
            int p = top.second.first, t = top.second.second;
            p++; t++;
            double gain = ((double)(p + 1) / (t + 1)) - ((double)p / t);
            pq.push({gain, {p, t}});
        }

        double sum = 0;
        while (!pq.empty()) {
            auto x = pq.top(); pq.pop();
            int p = x.second.first, t = x.second.second;
            sum += (double)p / t;
        }

        return sum / a.size();
    }
};