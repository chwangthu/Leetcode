//Feb 26 2018
//Convert the number into string can be much easier
class Solution {
public:
    int rotatedDigits(int N) {
        int ans = 0;
        for(int i = 1; i <= N; i++)
            if(checkGood(i)) ans++;
        return ans;
    }
    bool checkGood(int n) {
        string init = to_string(n);
        string tep = init;
        for(int i = 0; i < init.length(); i++) {
            if(init[i] == '3' || init[i] == '7' || init[i] == '4')
                return false;
            if(init[i] == '2') init[i] = '5';
            else if(init[i] == '6') init[i] = '9';
            else if(init[i] == '5') init[i] = '2';
            else if(init[i] == '9') init[i] = '6';
        }
        return (tep != init);
    }
};