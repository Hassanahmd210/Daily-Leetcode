class Solution {
public:
    char kthCharacter(int k) {
        string word  = "a";
        // if(word.size() > k){
        //     return word[k];
        // }
        while((int)word.length() < k){
            string temp = "";
            for (char ch : word){
                if(ch == 'z' ){
                    temp+= 'a';
                }
                else{
                    temp+= ch+1;
                }
            }
            word += temp;
        }

        return word[k-1];
    }
};