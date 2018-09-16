class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int tot_line = 1, cur_len = 0;
        for(int i = 0; i < S.length(); i++) {
            if(cur_len + widths[S[i] - 'a'] > 100) {
                tot_line += 1;
                cur_len = widths[S[i] - 'a'];
            }
            else cur_len += widths[S[i] - 'a'];
        }
        vector<int> ans;
        ans.push_back(tot_line); ans.push_back(cur_len);
        return ans;
    }
};