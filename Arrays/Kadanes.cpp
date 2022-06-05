#include <bits/stdc++.h> 
#define ll long long
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    ll maxSum = 0;
    ll maxSumTillIndex = 0;
    for(int i=0;i<n;i++){
        maxSumTillIndex+=arr[i];
        if(maxSumTillIndex > maxSum){
            maxSum = maxSumTillIndex;
        }
        if(maxSumTillIndex<0){
            maxSumTillIndex = 0;
        }
    }
    return maxSum;
}