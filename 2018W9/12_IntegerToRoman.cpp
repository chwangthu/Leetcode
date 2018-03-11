//Feb 28 2018
//制表法
class Solution {
public:
    string intToRoman(int num) {
        if(num <= 0) return "";
        string res = "";
        int numbers[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string match[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for(int i = 0; i < 13; i++) {
            while(num >= numbers[i]) {
                num -= numbers[i];
                res += match[i];
            }
        }
        return res;
    }
};