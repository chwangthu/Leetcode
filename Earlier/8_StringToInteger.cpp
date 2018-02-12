class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        int ans = 0, flag = 1, i = 0;
        if(!len) return 0;
        while(str[i] == ' ') i++;
        if(str[i] == '-')
        {
            flag = -1; i++;
        }
        else if(str[i] == '+') i++;
        int tep = 0;
        for(; i < len; i++)
        {
            if(str[i] < '0' || str[i] > '9') break;
            tep = ans * 10 + str[i] - '0';
            if(tep / 10 != ans)
            {
                if(flag == 1) return INT_MAX;
                else return INT_MIN;
            }
            ans = tep;
        }
        return ans*flag;
    }
};