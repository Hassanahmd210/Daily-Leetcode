class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> cnt(10, 0);
        for (char d : num) {
            cnt[d - '0']++;
        }

        string half = "", mid = "";
        for (int i = 9; i >= 0; --i) {
            while (cnt[i] >= 2) {
                half += (char)(i + '0');
                cnt[i] -= 2;
            }
        }

        for (int i = 9; i >= 0; --i) {
            if (cnt[i] > 0) {
                mid = (char)(i + '0');
                break;
            }
        }

        string revHalf = half;
        reverse(revHalf.begin(), revHalf.end());

        string res = half + mid + revHalf;
        return (!res.empty() && res[0] == '0') ? (mid.empty() ? "0" : mid) : res;
    }
};