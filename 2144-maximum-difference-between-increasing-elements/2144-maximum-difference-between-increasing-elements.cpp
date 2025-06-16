class Solution {
public:
    int maximumDifference(vector<int>& a) {
        int n = a.size();
        int max_diff = -1;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                if (a[i] < a[j]) {
                    int d = a[j] - a[i];
                    
                    if (d > max_diff){
                        max_diff = d;
                    }
                }
            }
        }
        return max_diff;
    }
};