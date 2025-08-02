class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> freq;
        
        for (int i = 0; i < basket1.size(); i++) {
            freq[basket1[i]]++;
        }
        
        for (int i = 0; i < basket2.size(); i++) {
            freq[basket2[i]]--;
        }
        
        vector<int> extra;
        
        for (auto it = freq.begin(); it != freq.end(); it++) {
            int val = it->first;
            int count = it->second;
            
            if (count % 2 != 0) {
                return -1;
            }
            
            for (int i = 0; i < abs(count) / 2; i++) {
                extra.push_back(val);
            }
        }
        
        sort(extra.begin(), extra.end());
        
        int minVal = INT_MAX;
        
        for (int i = 0; i < basket1.size(); i++) {
            if (basket1[i] < minVal) {
                minVal = basket1[i];
            }
        }
        
        for (int i = 0; i < basket2.size(); i++) {
            if (basket2[i] < minVal) {
                minVal = basket2[i];
            }
        }
        
        long long cost = 0;
        
        for (int i = 0; i < extra.size() / 2; i++) {
            cost += min(extra[i], 2 * minVal);
        }
        
        return cost;
    }
};
