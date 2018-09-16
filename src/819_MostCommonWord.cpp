class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) {
        unordered_set<string> b(banned.begin(), banned.end());
        unordered_map<string, int> cnt;
        for (auto & c: p) c = isalpha(c) ? tolower(c) : ' ';
        istringstream iss(p);
        string w;
        pair<string, int> res("", 0);
        while(iss >> w)
            if(b.find(w) == b.end() && ++cnt[w] > res.second)
                res = make_pair(w, cnt[w]);
        return res.first;
    }
};