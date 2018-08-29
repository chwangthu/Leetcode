//Mar 7 2018
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int s = strs.size();
        if(s <= 1) return "";
        string ans;
        int t = 0;
        while(1) {
            if(strs[0][t] == strs[1][t])
                { ans += strs[0][t]; t++; }
            else break;
        }
        if(s == 2) return ans;
        for(const string& f : strs) {
            t = 0;
            while(t < ans.length() && t < f.length() && f[t] == ans[t]) t++;
            ans = ans.substr(0, t);
        }
        return ans;
    }
};