//Feb 18 2018
//Dynamic Programming

//Version 1
//Time O(knm)
//ans[i][j]代表i到j不超过k+1条边最短路径长度
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
        const int INF = 1e9;
        vector<vector<int>> ans(n, vector<int>(n));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j) ans[i][j] = 0;
                else ans[i][j] = INF;
            }
        }
        K++;
        while(K--)
        {
            vector<vector<int>> nans = ans; //copy the former answer, else collision may happen
            for(const vector<int>& f: flights)
            {
                for(int i = 0; i < n; i++)
                {
                    nans[i][f[1]] = min(nans[i][f[1]], ans[i][f[0]] + f[2]);
                }
            }
            ans = nans;
        }
        if(ans[src][dst] >= INF - 7) return -1;
        return ans[src][dst];
    }
};

//Version 2
//Time O(km)
//dp[i][j] 代表从src用j条边走到i
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
        const int INF = 1e9;
        K++;
        vector<vector<int>> ans(n, vector<int>(K+1));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= K; j++)
            {
                ans[i][j] = INF;
            }
        }
        ans[src][0] = 0;
        for(int i = 1; i <= K; i++)
        {
            for(int j = 0; j < n; j++)
                ans[j][i] = ans[j][i-1];
            for(const vector<int>& f: flights)
            {
                ans[f[1]][i] = min(ans[f[1]][i], ans[f[0]][i-1] + f[2]);
            }
        }
        if(ans[dst][K] == INF) return -1;
        return ans[dst][K];
    }
};