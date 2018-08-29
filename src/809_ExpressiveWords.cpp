class Solution {
public:
    void shrink(string s, vector<char>& sh, vector<int>& num) {
        int cnt = 1;
        sh.clear(); num.clear();
        for(int i = 1; i < s.length(); i++) {
            if(s[i] != s[i-1]) {
                sh.push_back(s[i-1]); num.push_back(cnt);
                cnt = 1;
            }
            else cnt++;
            if(i == s.length() - 1) {
                sh.push_back(s[i]); num.push_back(cnt);
            }
        }
    }
    int expressiveWords(string S, vector<string>& words) {
        vector<char> sc; vector<int> snum;
        vector<char> tepc; vector<int> tepnum;
        shrink(S, sc, snum);
        int ans = 0;
        for(auto str: words) {
            shrink(str, tepc, tepnum);
            if(tepc.size() != sc.size()) continue;
            bool match = true;
            for(int i = 0; i < tepc.size(); i++) {
                if(tepc[i] != sc[i]) {match = false; break;}
                if(tepnum[i] == snum[i]) continue;
                if(tepnum[i] > snum[i]) {match = false; break;}
                if(snum[i] < 3) {match = false; break;}
            }
            if(match) ans++;
        }
        return ans;
    }
};