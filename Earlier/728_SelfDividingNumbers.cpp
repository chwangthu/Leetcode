class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++)
        {
            bool flag = false;
            int j = i;
            while(true)
            {
                int t = j % 10;
                if(t == 0 || (i % t != 0)) break;
                j /= 10;
                if(j == 0) { flag = true; break; }
            }
            if(flag) ans.push_back(i);
        }
        return ans;
    }
};