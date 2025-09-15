class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
     unordered_set<char> b;
    for (char c : brokenLetters) {
        b.insert(c);
    }

    stringstream ss(text);
    string w;
    int cnt = 0;

    while (ss >> w) {
        bool ok = true;
        for (char c : w) {
            if (b.count(c)) {
                ok = false;
                break;
            }
        }
        if (ok) cnt++;
    }

    return cnt;
}

};