class Solution {
public:
    bool isSafe(int col, int row, vector<vector<string>> &result, vector<string> &board, int n){
        int tempRow = row;
        int tempCol = col;
        //top-left diagonal
        while(tempRow >= 0 && tempCol >= 0){
            if(board[tempRow][tempCol] == 'Q') return false;
            tempRow--;
            tempCol--;
        }
        //left-row
        tempCol = col;
        while(tempCol>=0){
            if(board[row][tempCol] == 'Q') return false;
            tempCol--;
        }
        //bottom-left diagonal
        tempRow = row;
        tempCol = col;
        while(tempRow<n && tempCol >= 0){
            if(board[tempRow][tempCol] == 'Q') return false;
            tempRow++;
            tempCol--;
        }
        return true;
    }
    void solveNQueen(int col, vector<vector<string>> &result, vector<string> &board, int n){
        if(col == n){
            result.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(col,row,result,board,n)){
                board[row][col] = 'Q';
                solveNQueen(col+1, result, board, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        string s(n,'.');
        vector<string> board;
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        solveNQueen(0, result, board, n);
        return result;
    }
};