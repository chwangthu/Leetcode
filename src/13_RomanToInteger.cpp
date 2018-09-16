//Feb 28 2018
//If the right > cur then +cur
//else -cur
class Solution {
public:
    int romanToInt(string s) {
        int table[256];
        table['M'] = 1000;
        table['D'] = 500;
        table['C'] = 100;
        table['L'] = 50;
        table['X'] = 10;
        table['V'] = 5;
        table['I'] = 1;
        int res = 0;
        for(int i = 0; i < s.length(); i++) {
            if(i+1 >= s.length() || table[s[i+1]] <= table[s[i]]) {
                res += table[s[i]];
            }
            else res -= table[s[i]];
        }
        return res;
    }
};