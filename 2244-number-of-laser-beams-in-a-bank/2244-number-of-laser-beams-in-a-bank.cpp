class Solution {
public:
    int numberOfBeams(vector<string>& bank) {

        vector<int> dev;

        for (int i = 0; i < bank.size(); i++) {
            int cnt = 0;

            for (int j = 0; j < bank[i].size(); j++) {
                if (bank[i][j] == '1') { 
                    cnt++;
                }
            }
            if (cnt) {
                dev.push_back(cnt);
            }
        }

        if (dev.size() < 2) {
            return 0; 
        }
        int beams = 0;

        for (int i = 0; i < dev.size() - 1; i++) {
            beams += dev[i] * dev[i + 1];
        }
        return beams;
    }
};