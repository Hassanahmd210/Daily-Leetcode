class Solution {
public:
    int maximum69Number(int num) {
        string s = to_string(num);
        int ans = num;

        for (int i = 0; i < s.size(); i++) {
            char old = s[i];
            if (s[i] == '6') {
                s[i] = '9';
            }
            else if (s[i] == '9'){
                 s[i] = '6';
            }

            int temp = stoi(s);

            if (temp > ans) {
                ans = temp;
            }
            
            s[i] = old;
        }

        return ans;
    }
};