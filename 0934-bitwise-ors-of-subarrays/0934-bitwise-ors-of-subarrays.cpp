class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {

        unordered_set<int> res;
        unordered_set<int> cur;
        unordered_set<int> next;
        
        for (int x : arr) {

            next.clear();
            next.insert(x);

            for (int y : cur) {
                next.insert(x | y);
            }
            
            cur = next;
            res.insert(cur.begin(), cur.end());
        }
        
        return res.size();
    }
};
