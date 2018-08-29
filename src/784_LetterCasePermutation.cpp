//Feb 18 2018
//version 1 using bitmap
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        string dst;
        transform(S.begin(), S.end(), back_inserter(dst), ::tolower);
        int s = dst.length();
        int tot_let = 0;
        for(int i = 0; i < s; i++)
        {
            int tep = int(dst[i]);
            if(tep >= 97 && tep <= 122) tot_let++;
        }
        int tot = (1 << tot_let);
        vector<string> ans;
        for(int i = 0; i < tot; i++)    //tot cases, using bitmap
        {
            int k = tot_let - 1;
            string tep = dst;
            for(int j = 0; j < s; j++)
            {
                if(tep[j] >= 'a' && tep[j] <= 'z')
                {
                    if((i >> k) & 1) tep[j] -= 32;
                    k--;
                }
            }
            ans.push_back(tep);
        }
        return ans;
    }
};

//Iterative version
class Solution
{
public:
    vector<string> ans;
    void dfs(stirng s, int x)
    {
        if(x == s.length())
        {
            ans.push_back(s);
            return;
        }
        dfs(s, x+1);
        if(s[x] >= 'a' && s[x] <= 'z' || s[x] >= 'A' && s[x] <= 'Z')
        {
            s[x] ^= 'A' ^ 'a';
            dfs(s, x+1);
        }
    }
    vector<string> letterCasePermutation(string S){
        ans.clear();
        dfs(S, 0);
        return ans;
    }
}