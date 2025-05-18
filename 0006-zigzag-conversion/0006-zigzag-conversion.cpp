class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows == 1 || numRows >= s.length()){
        return s;
        }

        vector<string> rows(min(numRows, int(s.length())));
        int i = 0, step = 1;

        for (int j = 0; j < s.length(); j++) {
            rows[i] += s[j];
            if (i == 0) step = 1;
            else if (i == numRows - 1) step = -1;
            i += step;
        }

        string result = "";
        for (int j = 0; j < rows.size(); j++) {
            result += rows[j];
        }

        return result;
    }
};