#include <vector>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {

        int f[2][2] = {};
        int ans = 0;
        
        for (int x : nums) {
            int p = x % 2;

            for (int j = 0; j < 2; ++j) {

                int y = (j - p + 2) % 2;

                f[p][y] = f[y][p] + 1;

                ans = max(ans, f[p][y]);
            }
        }
        return ans;
    }
};
