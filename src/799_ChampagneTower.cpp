class Solution {
public:
    double f[105][105];
    double champagneTower(int poured, int query_row, int query_glass) {
        f[0][0] = poured;
        for(int i = 0; i <= query_row; i++) {
            for(int j = 0; j <= i; j++) {
                if(f[i][j] > 1) {
                    double d = f[i][j] - 1;
                    f[i][j] = 1;
                    f[i+1][j] += d / 2;
                    f[i+1][j+1] += d / 2;
                }
            }
        }
        return f[query_row][query_glass];
    }
};