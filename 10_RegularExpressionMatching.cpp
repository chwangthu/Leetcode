//2 Feb 2018
//using the method of dynamic programming
//dp[i][j] represents the state of s[0, i) and p[0, j)
//if dp[j-1] == '*' no repeat for dp[i][j-2]
//and repeat at least one time for dp[i-1][j]
//if dp[j-1] != '*' decrease for one character
class Solution {
public:
    bool isMatch(string s, string p) {
        int a = s.length(); int b = p.length();
        vector<vector<bool>> dp(a+1, vector<bool>(b+1, false));
        dp[0][0] = true;
        for(int i = 0; i <= a; i++)
            for(int j = 1; j <= b; j++)
            {
                if(p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j-2] || (i > 0 && dp[i-1][j] && (p[j-2] == s[i-1] || p[j-2] == '.'));
                }
                else
                {
                    dp[i][j] = (i > 0) && dp[i-1][j-1] && (p[j-1] == s[i-1] || p[j-1] == '.');
                }
            }
        return dp[a][b];
    }
};