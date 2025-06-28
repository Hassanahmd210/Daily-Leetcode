class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        
        for (int mask = 0; mask < (1 << 9); mask++) {
            int sum = 0, cnt = 0;
            for (int i = 0; i < 9; i++) {
                if (mask & (1 << i)) {
                    sum += i + 1;
                    cnt++;
                }
            }
            if (cnt == k && sum == n) {
                vector<int> tmp;
                for (int i = 0; i < 9; i++) {
                    if (mask & (1 << i)) {
                        tmp.push_back(i + 1);
                    }
                }
                res.push_back(tmp);
            }
        }
        return res;
    }
};