class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int xor1 = 0;
            for (int j = i; j < n; j++) {
                xor1 ^= arr[j]; 
                
                int xor2 = 0;
    
                for (int k = j + 1; k < n; k++) {
                    xor2 ^= arr[k];
                    if (xor1 == xor2) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
