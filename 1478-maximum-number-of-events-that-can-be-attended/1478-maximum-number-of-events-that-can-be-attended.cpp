class Solution {
public:
    int maxEvents(vector<vector<int>>& e) {
        
        //sorted by end date
        sort(e.begin(), e.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];   
        });

        set<int> days;
        for (int i = 1; i <= 100000; i++) {
            days.insert(i); 
        }

        int c = 0;
        for (int i = 0; i < e.size(); i++) {
            int s = e[i][0];
            int t = e[i][1];

            auto it = days.lower_bound(s); 

            if (it != days.end() && *it <= t) {
                c++;
                days.erase(it);
            }
        }

        return c;
    }
};