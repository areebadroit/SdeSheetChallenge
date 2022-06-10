#include <bits/stdc++.h> 
int uniquePaths(int m, int n, int i, int j,vector<vector<int>> &dp){
    if(i==m&&j==n){
        return 1;
    }
    if(i>m||j>n){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = uniquePaths(m,n,i,j+1,dp)+
        uniquePaths(m,n,i+1,j,dp);
}

int uniquePaths(int m, int n) {
	// Write your code here.
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return uniquePaths(m-1,n-1,0,0,dp);
}