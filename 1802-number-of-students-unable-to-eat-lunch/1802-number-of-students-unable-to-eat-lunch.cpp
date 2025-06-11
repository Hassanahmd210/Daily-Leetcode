class Solution {
public:
    int countStudents(vector<int>& s, vector<int>& sw) {
        int c[2] = {0};
        for (int x : s) {
            c[x]++;
        }
        for (int x : sw) {
            if (c[x] > 0) c[x]--;
            else {
                return c[0] + c[1];
            }
        }
        return 0;
    }
};