 bool isSafe(int col, int row, vector<vector<int>> &result, vector<vector<int>> &board, int n){
        int tempRow = row;
        int tempCol = col;
        //top-left diagonal
        while(tempRow >= 0 && tempCol >= 0){
            if(board[tempRow][tempCol] == 1) return false;
            tempRow--;
            tempCol--;
        }
        //left-row
        tempCol = col;
        while(tempCol>=0){
            if(board[row][tempCol] == 1) return false;
            tempCol--;
        }
        //bottom-left diagonal
        tempRow = row;
        tempCol = col;
        while(tempRow<n && tempCol >= 0){
            if(board[tempRow][tempCol] == 1) return false;
            tempRow++;
            tempCol--;
        }
        return true;
    }
    void solveNQueen(int col, vector<vector<int>> &result, vector<vector<int>> &board, int n){
        if(col == n){
            vector<int> resultRow;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    resultRow.push_back(board[i][j]);
                }
            }
            result.push_back(resultRow);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(col,row,result,board,n)){
                board[row][col] = 1;
                solveNQueen(col+1, result, board, n);
                board[row][col] = 0;
            }
        }
    }
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> result;
    vector<int> emptyRow(n,0);
    vector<vector<int>> board;
        for(int i=0;i<n;i++){
            board.push_back(emptyRow);
        }
        solveNQueen(0, result, board, n);
        return result;
}