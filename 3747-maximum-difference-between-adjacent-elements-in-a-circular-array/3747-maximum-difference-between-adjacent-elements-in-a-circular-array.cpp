class Solution {
public:
    int maxAdjacentDistance(vector<int>& n) {
        int m = 0;
        int s = n.size();
        for (int i = 0; i < s; i++) {

            int d = abs(n[i] - n[(i + 1) % s]);
            
            if (d > m) {
                m = d;
            }
        }
        return m;
    }
};