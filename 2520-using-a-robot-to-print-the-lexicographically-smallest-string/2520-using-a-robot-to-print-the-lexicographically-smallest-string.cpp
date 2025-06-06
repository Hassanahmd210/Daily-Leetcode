class Solution {
public:
    string robotWithString(string s) {
    string result = "";
    stack<char> t;
    vector<char> minSuffix(s.length() + 1, 'z' + 1); 
    int n = s.length();

    for (int i = n - 1; i >= 0; --i) {
        minSuffix[i] = min(s[i], minSuffix[i + 1]);
    }

    int i = 0;
    while (i < n || !t.empty()) {
        if (!t.empty() && (i == n || t.top() <= minSuffix[i])) {
            result += t.top();
            t.pop();
        } else {
            t.push(s[i]);
            i++;
        }
    }
    
    return result;
}


};