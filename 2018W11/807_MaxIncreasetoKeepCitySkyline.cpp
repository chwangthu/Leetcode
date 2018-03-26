class Solution {
public:
    vector<vector<int>> mgrid;
    int n, m;
    int findRow(int t) {
        int max = -1;
        for(int i = 0; i < m; i++) {
            if(max < mgrid[t][i]) max = mgrid[t][i];
        }
        return max;
    }
    int findColumn(int t) {
        int max = -1;
        for(int i = 0; i < n; i++) {
            if(max < mgrid[i][t]) max = mgrid[i][t];
        }
        return max;
    }
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        mgrid = grid;
        n = grid.size();    //row
        m = grid[0].size(); //column
        int ans = 0;
        vector<int> row, col;
        for(int i = 0; i < n; i++) row.push_back(findRow(i));
        for(int i = 0; i < m; i++) col.push_back(findColumn(i));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                ans += min(row[i], col[j]) - grid[i][j];
            }
        return ans;
    }
};
