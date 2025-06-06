class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& t) {
        int time = 0, lm = 0, lp = 0, lg = 0, cm = 0, cp = 0, cg = 0;
        
        for (int i = 0; i < g.size(); i++) {
            for (char c : g[i]) {
                if (c == 'M') {
                     cm++; lm = i; 
                    }
                if (c == 'P') { 
                    cp++; lp = i; 
                    }
                if (c == 'G') {
                     cg++; lg = i;
                    }
            }
        }

        time += cm + cp + cg;

        for (int i = 1; i < t.size(); i++) {
            t[i] += t[i - 1]; 
            }

        if (lm > 0) {
             time += t[lm - 1]; 
            }
        if (lp > 0) {
             time += t[lp - 1]; 
            }
        if (lg > 0) {
             time += t[lg - 1]; 
            }

        return time;
    }
};