class Solution {
public:
    string makeFancyString(string s) {
        string r = "";
        for(int i =0 ;i<s.length() ; i++){
            int l = r.length();
            if(l>=2 && r[l-1] == s[i] && r[l-2] ==s[i]){
                continue;
            }
            r += s[i];
         

        }
        return r;
    }
};