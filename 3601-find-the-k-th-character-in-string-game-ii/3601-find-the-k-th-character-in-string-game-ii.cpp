class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();
        vector<long long> prev(n), len(n);
        long long l = 1;
        
        for (int i = 0; i < n; i++) {
            prev[i] = min(l, k);
            l = min(l * 2, k + 1);
            len[i] = l;
        }
        
        int shift = 0;
        for (int i = n - 1; i >= 0; i--) {
            long long half = prev[i];
            if (k > half) {
                k -= half;
                if (operations[i] == 1)
                    shift = (shift + 1) % 26;
            }
        }
        
        return char('a' + shift);
    }
};