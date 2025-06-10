class Solution {
public:
    int numRabbits(vector<int>& a) {
        unordered_map<int, int> m;
        for (int i = 0; i < a.size(); i++) {
            m[a[i]]++;
        }

        int t = 0;
        
        for (auto it = m.begin(); it != m.end(); it++) {
            int x = it->first, c = it->second;
            int g = (c + x) / (x + 1);
            t += g * (x + 1);
        }
        return t;
    }
};