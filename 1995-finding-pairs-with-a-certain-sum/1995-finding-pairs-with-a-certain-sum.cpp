class FindSumPairs {
    vector<int> a, b;
    unordered_map<int,int> f;

public:
    FindSumPairs(vector<int>& x, vector<int>& y) {
        a = x;
        b = y;

        for (int v : b) 
            f[v]++;
    }

    void add(int i, int v) {
        f[b[i]]--;
        if (f[b[i]] == 0) 
            f.erase(b[i]);
        b[i] += v;
        f[b[i]]++;
    }

    int count(int t) {
        int c = 0;
        for (int v : a) {
            auto it = f.find(t - v);
            if (it != f.end()) 
                c += it->second;
        }
        return c;
    }
};