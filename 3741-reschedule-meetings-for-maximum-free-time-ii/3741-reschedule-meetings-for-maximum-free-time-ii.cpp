class Solution {
public:
    int maxFreeTime(int T, vector<int>& S, vector<int>& E) {
        int n = S.size();
        if (n == 0) 
            return T;

        vector<pair<int,int>> ev(n);
        for (int i = 0; i < n; ++i)
            ev[i] = {S[i], E[i]};
        sort(ev.begin(), ev.end());
        for (int i = 0; i < n; ++i) {
            S[i] = ev[i].first;
            E[i] = ev[i].second;
        }

        vector<int> gaps(n + 1);
        gaps[0] = S[0];
        for (int i = 1; i < n; ++i)
            gaps[i] = S[i] - E[i - 1];
        gaps[n] = T - E[n - 1];

        vector<int> rightMax(n + 1);
        rightMax[n] = 0;
        for (int i = n - 1; i >= 0; --i)
            rightMax[i] = max(rightMax[i + 1], gaps[i + 1]);

        int answer = 0, leftMax = 0;
        for (int i = 1; i <= n; ++i) {
            int dur = E[i - 1] - S[i - 1];

            answer = max(answer, gaps[i - 1] + gaps[i]);

            if (leftMax >= dur || rightMax[i] >= dur) {
                answer = max(answer, gaps[i - 1] + gaps[i] + dur);
            }

            leftMax = max(leftMax, gaps[i - 1]);
        }

        return answer;
    }
};