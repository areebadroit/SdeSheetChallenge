#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
    if(m==0){
        return arr2;
    }
    if(n==0){
        return arr1;
    }
    int i=0,j=0;
    vector<int> temp;
    while(i<m&&j<n){
        if(arr1[i]<=arr2[j]){
            temp.push_back(arr1[i++]);
        }else{
            temp.push_back(arr2[j++]);
        }
    }
    while(i<m){
        temp.push_back(arr1[i++]);
    }
    while(j<n){
       temp.push_back(arr2[j++]);
    }
    return temp;
}