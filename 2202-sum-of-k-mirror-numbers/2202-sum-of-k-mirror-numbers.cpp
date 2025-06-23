#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long kMirror(int k, int n) {
        auto isP = [&](const string &s) {
            int i = 0, j = s.size() - 1;
            while (i < j) {
                if (s[i++] != s[j--]) 
                    return false;
            }
            return true;
        };

        auto toB = [&](long long x) {
            if (x == 0) return string("0");
            string r;
            while (x > 0) {
                r.push_back('0' + (x % k));
                x /= k;
            }
            reverse(r.begin(), r.end());
            return r;
        };
        
        long long ans = 0;
        int cnt = 0;
        
        for (int x = 1; x <= 9 && cnt < n; x++) {
            string b = toB(x);
            if (isP(b)) {
                ans += x;
                cnt++;
            }
        }
        
        int len = 2;
        while (cnt < n) {

            int hlen = (len + 1) / 2;
            long long st = 1;
            for (int i = 1; i < hlen; i++) {
                st *= 10;
            }

            long long en = st * 10 - 1;
            bool odd = (len % 2 == 1);
            
            for (long long x = st; x <= en && cnt < n; x++) {

                string h = to_string(x);
                string pal = h;

                int cut = odd ? (int)h.size() - 1 : (int)h.size();

                for (int i = cut - 1; i >= 0; i--) 
                    pal.push_back(h[i]);
                
                long long v = stoll(pal);
                
                if (isP(toB(v))) {
                    ans += v;
                    cnt++;
                }
            }
            
            len++;
        }
        
        return ans;
    }
};
