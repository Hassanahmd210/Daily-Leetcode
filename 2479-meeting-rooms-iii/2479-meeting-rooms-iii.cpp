class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; ++i) {
            available.push(i);
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> ongoing;
        vector<int> count(n, 0);

        for (auto& meet : meetings) {
            int start = meet[0];
            int end = meet[1];

            while (!ongoing.empty() && ongoing.top().first <= start) {
                int room = ongoing.top().second;
                ongoing.pop();
                available.push(room);
            }

            if (!available.empty()) {
                int room = available.top();
                available.pop();
                ongoing.push({end, room});
                count[room]++;
            } else {
                auto [freeTime, room] = ongoing.top();
                ongoing.pop();
                long long duration = end - start;
                ongoing.push({freeTime + duration, room});
                count[room]++;
            }
        }

        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (count[i] > count[ans] || (count[i] == count[ans] && i < ans)) {
                ans = i;
            }
        }

        return ans;
    }
};