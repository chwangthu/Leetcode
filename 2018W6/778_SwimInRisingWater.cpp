//10 Feb 2018
//To be updated
const int MAXN = 50;
int pre[MAXN*MAXN];
int find(int x) //find the root of x
{
    if(pre[x] != x) pre[x] = find(pre[x]);
    return pre[x];
}

bool join(int x, int y) //merge x and y branch
{
    int r1 = find(x), r2 = find(y);
    if(r1 == r2) return false;
    pre[r1] = r2;
    return true;
}

struct Square
{
    int r, c, h;
    bool operator<(const Square& tep) const
    {
        return h < tep.h;
    }
};

int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<Square> squares;
        squares.reserve(n*n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                pre[i*n + j] = i * n + j;
                squares.push_back(Square{i, j, grid[i][j]});
            }
        sort(squares.begin(), squares.end()); //sort first
        for(int t = 0; t < squares.size(); t++)
        {
            int r = squares[t].r, c = squares[t].c;
            for(int d = 0; d < 4; d++)
            {
                int nr = r + dir[d][0], nc = c + dir[d][1];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] <= t)
                    join(r * n + c, nr * n + nc);
            }
            if(find(0) == find(n*n - 1)) return t;
        }
        return -1;
    }
};