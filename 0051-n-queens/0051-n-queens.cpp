class Solution {
public:

    bool isSafe(int row ,int cols,vector<string>& board,int n) {
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


        //diagonally as at this position there is not any queen in the botton position then the current queen so we only check the above queen and diagonal 


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




    void nQueen(vector<string>& board ,vector<vector<string>>& ans , int n ,int row) {
        if(row==n) {
            ans.push_back(board);
            return;
        }

        for(int j=0;j<n;j++) {
            if(isSafe(row,j,board,n)) {
                board[row][j]='Q';
                nQueen(board,ans,n,row+1);
                board[row][j]='.';
            }
        }
    }



    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        nQueen(board,ans ,n,0);

        return ans ;
    }
};