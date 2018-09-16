class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int num1 = 0, num2 = 0;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == 'X') num1++;
                else if(board[i][j] == 'O') num2++;
            }
        if(abs(num1 - num2) >= 2) return false;
        if(num2 > num1) return false;
        int a1 = checkEnd(board, 'X');
        int a2 = checkEnd(board, 'O');
        if(a1 > 2 || a2 > 2) return false;  //不可能X和O都有2个相等
        if(a1 > 0 && a2 != 0) return false;
        if(a2 > 0 && a1 != 0) return false;
        if(a1 > 0 && num1 == num2) return false;
        if(a2 > 0 && num1 > num2) return false;
        return true;
    }
    int checkEnd(vector<string>& board, char x)
    {
        int ans = 0;
        for(int i = 0; i < 3; i++) {
            if(board[i][0] == x && board[i][0] == board[i][1] && board[i][1] == board[i][2]) ans++;
        }   //行相等
        for(int i = 0; i < 3; i++) {
            if(board[0][i] == x && board[0][i] == board[1][i] && board[1][i] == board[2][i]) ans++;
        }   //列相等
        if(board[0][0] == x && board[0][0] == board[1][1] && board[1][1] == board[2][2])
            ans++;
        if(board[0][2] == x && board[0][2] == board[1][1] && board[1][1] == board[2][0]) ans++;
        return ans;
    }
};