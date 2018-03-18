class Solution {
public:
    int hex2int(const string& hexStr)
    {
        char *offset;
        if(hexStr.length() > 2) {
            if(hexStr[0] == '0' && hexStr[1] == 'x') {
                return strtol(hexStr.c_str(), &offset, 0);
            }
        }
        return strtol(hexStr.c_str(), &offset, 16);
    }
    int match[16] = {0, 17, 34, 51, 68, 85, 102, 119, 136, 153, 170, 187, 204, 221, 238, 255};
    string str = "0123456789abcdef";
    int find_min(string s) {
        int min = 0x7ffffff;
        int tep = hex2int(s);
        int res = 0;
        for(int i = 0; i <= 15; i++) {
            int cmp = (match[i] - tep) * (match[i] - tep);
            if(cmp < min) {
                min = cmp;
                res = i;
            }
        }
        return res;
    }
    string similarRGB(string color) {
        string ans;
        ans += "#";
        string tep = "0x";
        int a = find_min(tep + color.substr(1, 2));
        int b = find_min(tep + color.substr(3, 2));
        int c = find_min(tep + color.substr(5, 2));
        ans += str.substr(a, 1);
        ans += str.substr(a, 1);
        ans += str.substr(b, 1);
        ans += str.substr(b, 1);
        ans += str.substr(c, 1);
        ans += str.substr(c, 1);
        return ans;
    }
};