#define lli long long int
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
    vector<vector<long long int>> pascalsTriangle(n);
    for(lli rowIndex=0;rowIndex<n;rowIndex++){
        pascalsTriangle[rowIndex].resize(rowIndex+1);
        lli firstColIndex = 0;
        lli lastColIndex = rowIndex;
        pascalsTriangle[rowIndex][firstColIndex] = pascalsTriangle[rowIndex][lastColIndex] = 1;
        for(lli colIndex = 1; colIndex < rowIndex; colIndex++){
            pascalsTriangle[rowIndex][colIndex] = pascalsTriangle[rowIndex-1][colIndex-1]+pascalsTriangle[rowIndex-1][colIndex];
        }
    }
    return pascalsTriangle;
}
