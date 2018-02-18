//Feb 13 2018
//A problem that costs me a long time

//Property: 
//1. To tranform columns, you must exchange rows and vice versa

//2. The beginning board contains only two different kinds of rows(columns), and the two kinds are 0/1 reversed
//This is correct because after a swap of rows, columns that are the same remains the same, different remains the different
//and final board has only two kinds of rows(columns), so the beginning must be also
//As for why they are 0/1 reversed, prove by contradiction. If there are two different rows like these: [0, ....., 1] and [0, ....., 0]
//Then no matter how you swap rows and columns, there must be a rectangular whose four corners are 0,1,0,1, it cannot be a chessboard!!!

//3.A row swap followed by a column swap is the same as the opposite. So we can swap rows first, then columns
//If the minimum swaps consists of a sequence like RCCR....(R for row swap, C for column swap)


//4. If this chessboard can be tranformed (We can check that first), then if the first row and column is legal, the whole will also be legal.
//To check, verify the property 2. 
//If we first perform row swaps and make the first column legal, then according to 2(two different columns remain 0/1 reversed after row swaps),
//every column is equal to the first or 0/1 reversal, then all columns are legal, then we can perform column swaps and make the first row legal.


//So we can write code like this:
//1) verify property 2
//2) swap columns and swap rows
//count the number num of displaced 0/1, the number of swap is num/2
//3) add column swaps and row swaps
class Solution {
public:
    bool check(vector<vector<int>>& board)
    {
        int s = board.size();
        vector<int> row0, row1;
        vector<int> col0, col1; //两种不同的行和列
        row0 = board[0];
        for(int i = 0; i < s; i++)
            row1.push_back(row0[i]^1);
        for(int i = 0; i < s; i++)
        {
            col0.push_back(board[i][0]);
            col1.push_back(board[i][0] ^ 1);
        }
        if(!checkSingle(row0) || !checkSingle(col0))
            return false;
        for(int i = 0; i < s; i++)
        {
            vector<int> col;
            for(int j = 0; j < s; j++)
                col.push_back(board[j][i]);
            if(!checkSingle(col, col0) && !checkSingle(col, col1))
                return false;
            if(!checkSingle(board[i], row0) && !checkSingle(board[i], row1))
                return false;
        }
        return true;
    }
    bool checkSingle(vector<int>& v, vector<int>& formal)
    {
        for(int i = 0; i < v.size(); i++)
            if(v[i] != formal[i]) return false;
        return true;
    }
    bool checkSingle(vector<int>& board)
    {
        int n0 = 0, n1 = 0;
        for(int i = 0; i < board.size(); i++)
        {
            if(board[i] == 0) n0 += 1;
            else n1 += 1;
        }
        if(abs(n0 - n1) > 1) return false;
        return true;
    }
    int getRes(vector<int>& board)  //Assume in final state board[0][0] = 0
    {
        int ans = INT_MAX, mismatch = 0;
        int s = board.size();
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < s; i++)
        {
            int need = i % 2;
            if(board[i] != need) mismatch++;
            if(board[i] == 0) cnt1++;
            if(need == 0) cnt2++;
        }
        if(cnt1 == cnt2)
            ans = mismatch / 2;
        return ans;
    }
    int movesToChessboard(vector<vector<int>>& board) {
        if(check(board))
        {
            vector<int> row0 = board[0];
            vector<int> col0;
            for(int i = 0; i < board.size(); i++)
                col0.push_back(board[i][0]);
            int row, col;
            row = getRes(row0);
            col = getRes(col0);
            for(int i = 0; i < board.size(); i++)
            {
                row0[i] ^= 1;   col0[i] ^= 1;
            } //xor, final state board[0][0] = 1
            row = min(row, getRes(row0));   //find the min between board[0][0] = 0 and board[0][0] = 1
            col = min(col, getRes(col0));
            if(row != INT_MAX && col != INT_MAX)
                return row + col;
            else return -1;
        }
        return -1;
    }
};