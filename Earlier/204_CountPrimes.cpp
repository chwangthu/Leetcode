class Solution {
public:
    int countPrimes(int n) {
        int* mark = new int[n];
        for(int i = 0; i < n; i++) mark[i] = 0;
        mark[0] = 1; mark[1] = 1;
        for(int i = 2; i * i < n; i++)
        {
            if(!mark[i]) 
                for(int j = i*i; j < n; j += i) mark[j] = 1;
        }
        int res = 0;
        for(int i = 0; i < n; i++)
            if(mark[i] == 0) res++;
        return res;
    }
};