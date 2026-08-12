class Solution {
public:

    bool isSafe(vector<vector<char>>& board,int row,int col,int dig) {
        //horizontal 
        char digi='0'+dig;
        for(int i=0;i<9;i++) {
            if(digi==board[row][i]) {
                return false;
            }
        }

        //verticle


        for(int i=0;i<9;i++) {
            if(digi==board[i][col]) {
                return false;
            }
        }



        //check for the grid 

        int strR=(row/3)*3;
        int strC=(col/3)*3;

        int endR=strR+2;
        int endC=strC+2;
        
        for(int i=strR;i<=endR;i++) {
            for(int j=strC;j<=endC;j++) {
                if(board[i][j]==digi) {
                    return false;
                }
            }
        }

        return true;
    }

    bool ss(vector<vector<char>>& board,int row,int cols) {
        if(row==9) {
            return true;
        }

        if(board[row][cols]!='.') {
            int nextRow=row;
            int nextCols=cols+1;

            if(nextCols==9) {
                nextRow=row+1;
                nextCols=0;
            }
            return ss(board,nextRow,nextCols);
        }

        for(int dig=1 ;dig<=9;dig++) {
            if(isSafe(board,row,cols,dig)) {
                board[row][cols]='0'+dig;

                int nextRow=row;
                int nextCols=cols+1;

                if(nextCols==9) {
                    nextRow=row+1;
                    nextCols=0;
                }
                if(ss(board,nextRow,nextCols)) {
                    return true;
                }
                board[row][cols]='.';
            }
        }
        return false;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        ss(board,0,0);
    }
};