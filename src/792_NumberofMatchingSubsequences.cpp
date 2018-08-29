class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int ans = 0;
        vector<int> table;
        for(int i = 0; i < words.size(); i++) {
            bool found_pre = false;
            for(int j = 0; j < i; j++) {
                if(words[i] == words[j]) {
                    ans += table[j];
                    table.push_back(table[j]);
                    found_pre = true;
                    break;
                }
            }
            if(found_pre) continue;
            if(checkString(words[i], S)) {
                ans++;
                table.push_back(1);
            }
            else table.push_back(0);
        }
        return ans;
    }
    bool checkString(string toCheck, string s) { //是否含有toCheck字符串
        int j = 0;
        for(int i = 0; i < s.length(); i++) {
            if(j == toCheck.length()) return true;
            if(toCheck[j] == s[i]) { j++; continue;}
        }
        if(j >= toCheck.length()) return true;
        return false;
    }
};