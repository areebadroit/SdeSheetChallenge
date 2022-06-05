#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
    // Most optimal approach
    int rowLen = matrix.size();
    int colLen = matrix[0].size();
    bool firstColZero = false;
    for(int rowIndex = 0; rowIndex < rowLen; rowIndex++){
        if(matrix[rowIndex][0]==0) firstColZero = true;
        for(int colIndex = 1; colIndex < colLen; colIndex++){
            if(matrix[rowIndex][colIndex]==0){
                matrix[rowIndex][0] = 0;
                matrix[0][colIndex] = 0;
            }
        }
    }
    for(int rowIndex = rowLen-1; rowIndex >= 0; rowIndex--){
        for(int colIndex = colLen-1; colIndex >= 1; colIndex--){
            if(matrix[rowIndex][0]==0|| matrix[0][colIndex]==0){
                matrix[rowIndex][colIndex] = 0;
            }
        }
        if(firstColZero) matrix[rowIndex][0] = 0;
    }
    
}