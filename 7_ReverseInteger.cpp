//4 Feb 2018
//type cast x into long long, then it is easy to judge whether there is an overflow
//note the properties of N or P

class Solution {
public:
    int reverse(int x) {
        bool flag = false;
        if(x < 0) flag = true;
        long long tep = (long long)(x); //type cast
        if(tep < 0) tep = -tep;
        long long res = 0;
        while(tep != 0)
        {
            res = res * 10 + tep % 10;
            tep /= 10;
        }
        if(res > INT_MAX) return 0; //judge overflow
        if(flag) return -res;
        return res;
    }
};

//In fact, we can write in the same way no matter the x is p or n
class Solution {
public:
    int reverse(int x)
    {
        int res = 0;
        while (x != 0)
        {
            if (abs(res) > INT_MAX / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};