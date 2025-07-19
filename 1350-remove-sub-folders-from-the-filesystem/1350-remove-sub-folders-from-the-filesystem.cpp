class Solution {
public:
    vector<string> removeSubfolders(vector<string>& f) {
        
        sort(f.begin(), f.end());
        vector<string> res;

        for (auto& s : f) {

            if (res.empty()  ||  s.find(res.back() + "/") != 0) {

                res.push_back(s);

            }

        }
        
        return res;
    }
};