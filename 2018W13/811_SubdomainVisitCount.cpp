class Solution {
public:
    vector<string> split(string& s) {
        vector<string> res;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                res.push_back(s.substr(0, i+1));
                res.push_back(s.substr(i+1));
            }
            if(s[i] == '.') res.push_back(s.substr(i+1));
        }
        return res;
    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
       vector<string> ans;
       return ans; 
    }
};