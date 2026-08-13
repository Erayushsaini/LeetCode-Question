class Solution {
public:

    bool isSafe(vector<vector<char>>& board,int row,int col) {
        //horizontal check 

        for(int i=0;i<9;i++) {
            if(i==col) {
                continue;
            }
            if(board[row][i]==board[row][col]) {
                return false;
            }
        }

        //verticle check 

        for(int i=0;i<9;i++) {
            if(i==row) {
                continue;
            }
            if(board[i][col]==board[row][col]) {
                return false;
            }
        }

        //grid check 
        int strR=(row/3)*3;
        int endR=strR+2;

        int strC=(col/3)*3;
        int endC=strC+2;
        for(int i=strR;i<=endR;i++) {
            for(int j=strC;j<=endC;j++) {

                if(i==row && j==col) {
                    continue;
                }
                if(board[i][j]==board[row][col]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool Vs(vector<vector<char>>& board ,int row,int col) {
        int nextR,nextC;
        if(row==9) {
            return true;
        }
        if(board[row][col]=='.') {
            nextR=row;
            nextC=col+1;

            if(nextC==9) {
                nextR=row+1;
                nextC=0;
            }
            return Vs(board,nextR,nextC);
        }

        if(isSafe(board,row,col)) {
            nextR=row;
            nextC=col+1;

            if(nextC==9) {
                nextR=row+1;
                nextC=0;
            }
            return Vs(board,nextR,nextC);
        }else {
            return false;
        }


    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return Vs(board,0,0);
    }
};