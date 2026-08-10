class Solution {
public:


    bool isSafe(int n ,vector<string>& board,int row,int cols) {
        //horizontal 
        for(int i=0;i<n;i++) {
            if(board[row][i]=='Q') {
                return false;
            }
        }

        //verticle 

        for(int i=0;i<n;i++) {
            if(board[i][cols]=='Q') {
                return false;
            }
        }
        //right diagonal 

        for(int i=row,j=cols;i>=0 && j>=0;i--,j--) {
            if(board[i][j]=='Q') {
                return false;
            }
        }

        for(int i=row , j=cols ; i>=0 && j<n;i--,j++) {
            if(board[i][j]=='Q') {
                return false;
            }
        }

        return true;
    }

    void nQueen(int n ,int& ans ,vector<string>& board,int row) {
        if(row==n) {
            ans++;
            return;
        }

        for(int j=0;j<n;j++) {
            if(isSafe(n,board,row,j)) {
                board[row][j]='Q';
                nQueen(n,ans,board,row+1);
                board[row][j]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));

        int ans=0;
        int row=0;
        nQueen(n,ans,board,row);

        return ans;
    }
};