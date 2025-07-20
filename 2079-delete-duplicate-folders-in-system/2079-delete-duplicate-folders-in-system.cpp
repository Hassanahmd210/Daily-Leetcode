class Solution {
public:
    struct T {
        map<string, T*> c;
        string n;
        bool del = false;
        T(string nn): n(nn) {}
    };
    
    T* build(vector<vector<string>>& p) {
        T* root = new T("");
        for (auto& pa : p) {
            T* cur = root;
            for (auto& s : pa) {
                if (!cur->c.count(s)) cur->c[s] = new T(s);
                cur = cur->c[s];
            }
        }
        return root;
    }

    string ser(T* node, unordered_map<string, vector<T*>>& m) {
        if (node->c.empty()) return "";
        vector<string> v;
        for (auto& a : node->c) v.push_back(a.first + "(" + ser(a.second, m) + ")");
        sort(v.begin(), v.end());
        string ret = "";
        for (auto& s : v) ret += s;
        m[ret].push_back(node);
        return ret;
    }

    void mark(unordered_map<string, vector<T*>>& m) {
        for (auto& a : m)
            if (a.second.size() > 1)
                for (auto x : a.second) x->del = true;
    }

    void col(T* node, vector<string>& path, vector<vector<string>>& ans) {
        for (auto& a : node->c) {
            T* nxt = a.second;
            if (nxt->del) continue;
            path.push_back(nxt->n);
            ans.push_back(path);
            col(nxt, path, ans);
            path.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        T* root = build(paths);
        unordered_map<string, vector<T*>> mp;
        ser(root, mp);
        mark(mp);
        vector<vector<string>> ans;
        vector<string> cur;
        col(root, cur, ans);
        return ans;
    }
};