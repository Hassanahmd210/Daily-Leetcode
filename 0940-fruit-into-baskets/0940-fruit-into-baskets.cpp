
class Solution {
public:
    int totalFruit(vector<int>& f) {
        unordered_map<int,int> b;
        int l = 0, res = 0, n = f.size();

        for(int r = 0; r < n; ++r) {
            b[f[r]]++;

            while(b.size() > 2) {
                b[f[l]]--;

                if(b[f[l]] == 0)
                    b.erase(f[l]);

                l++;
            }
            
            res = max(res, r - l + 1);
        }
        return res;
    }
};
