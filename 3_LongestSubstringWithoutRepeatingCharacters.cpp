//2 Feb 2018
//O(n^2) algorithm
//find the longest substring without repeating character with 
//the starting point of every postion of string s, update the 
//length at every postion
//To find the longest one, extends the substring of the right 
//character is not in the current substring until it cannot be 
//extended
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(s.empty()) return 0;
        int ans = 1;
        for(int i = 0; i < len; i++)    //Find the longest substring with the start point of i
        {
            string tep = s.substr(i, 1);
            for(int j = i + 1; j < len; j++)
            {
                if(tep.find(s.substr(j, 1)) == string::npos) //extend the substring
                    tep.append(s.substr(j, 1));
                else break;
            }
            int len1 = tep.length();
            ans = max(len1, ans); //update the answer
        }
        return ans;
    }
};

//Another method
int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }