//Day 3
#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
    int start = 0;
    int end = (m*n)-1;
    while(start<=end){
        int mid = (start + (end - start) / 2);
        if(mat[mid/n][mid%n]==target){
            return true;
        }
        else if(mat[mid/n][mid%n]<target){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return false;
}