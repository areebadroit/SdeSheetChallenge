class Solution {
public:
    void solveNQueen(int col, vector<vector<string>> &result, vector<string> &board, int n, vector<bool> &topLeftDiagonal, vector<bool> &leftCols, vector<bool> &bottomLeftDiagonal){
        if(col == n){
            result.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(topLeftDiagonal[row+col]==false&&leftCols[row]==false&&bottomLeftDiagonal[n-1+col-row]==false){
                board[row][col] = 'Q';
                topLeftDiagonal[row+col]=true;
                leftCols[row]=true;
                bottomLeftDiagonal[n-1+col-row]=true;
                solveNQueen(col+1, result, board, n,topLeftDiagonal,leftCols,bottomLeftDiagonal);
                board[row][col] = '.';
                topLeftDiagonal[row+col]=false;
                leftCols[row]=false;
                bottomLeftDiagonal[n-1+col-row]=false;
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
        vector<bool> topLeftDiagonal(2*n-1,false);
        vector<bool> leftCols(n,false);
        vector<bool> bottomLeftDiagonal(2*n-1,false);
        solveNQueen(0, result, board, n,topLeftDiagonal,leftCols,bottomLeftDiagonal);
        return result;
    }
};