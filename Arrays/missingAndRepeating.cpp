#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
    int xorOneToN = 1;
    for(int i=2;i<=n;i++){
        xorOneToN=xorOneToN^i;
    }
    int xorArr = arr[0];
    for(int i=1;i<n;i++){
        xorArr=xorArr^arr[i];
    }
    int xXORy = xorOneToN ^ xorArr;
    int r = 0;
    while(!((xXORy>>r)&1)) r++;
    int bucketOne=0;
    int bucketTwo=0;
    for(int i = 1;i<=n;i++){
        if((i>>r)&1){
            bucketOne = bucketOne ^ i;
        }else{
            bucketTwo = bucketTwo ^ i;
        }
    }
    for(int i = 0;i<n;i++){
        if((arr[i]>>r)&1){
            bucketOne = bucketOne ^ arr[i];
        }else{
            bucketTwo = bucketTwo ^ arr[i];
        }
    }
    pair<int,int> result;
    for(int i=0;i<n;i++){
        if(arr[i] == bucketOne){
            result.second = arr[i];
            result.first = bucketTwo;
            break;
        }
        else if(arr[i] == bucketTwo){
            result.second = arr[i];
            result.first = bucketOne;
            break;
        }
    }
    return result;
}
