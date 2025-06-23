class Solution {
public:
    vector<string> divideString(string s, int k, char f) {

        vector<string> res;
        int n = s.size();
        int idx = 0;
        
        while (idx < n) {
            
            string grp = "";

            for (int j = 0; j < k; j++) {

                if (idx < n) {
                    grp.push_back(s[idx]);
                    idx++;
                } 
                else {
                    grp.push_back(f);
                }
            }

            res.push_back(grp);
        }
        
        return res;
    }
};
