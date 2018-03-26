class Solution {
public:
    vector<string> Morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    string interpret(string S) {
        string ans;
        for(int i = 0; i < S.length(); i++) {
            ans += Morse[S[i] - 'a'];
        }
        return ans;
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> cur;
        int ans = 0;
        for(int i = 0; i < words.size(); i++) {
            string tep = interpret(words[i]);
            //cout << tep << endl;
            if(find(cur.begin(), cur.end(), tep) == cur.end()) {
                cur.push_back(tep);
                ans++;
            }
        }
        return ans;
    }
};