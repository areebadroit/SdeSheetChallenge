//Day 3
#include <bits/stdc++.h> 
int mergeAndCount(vector<int> &arr, int start, int mid, int end){
    int count = 0;
    vector<int> temp;
    int j = mid+1;
    for(int i = start; i<=mid;i++){
        while(j<=end&&arr[i]>2LL*arr[j]){
            j+=1;
        }
        count+=(j-(mid+1));
    }
    int i = start;
    j = mid+1;
    while(i<=mid&&j<=end){  
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }    
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=end){
        temp.push_back(arr[j++]);
    }
    int q = 0;
    for(int p=start;p<=end;p++){
        arr[p]=temp[q++];
    }
    return count;
}
int divide(vector<int> &arr, int start, int end){
    int count = 0;
    if(start<end){
        int mid = (start+end)/2;
        count+=divide(arr,start,mid);
        count+=divide(arr,mid+1,end);
        count+=mergeAndCount(arr,start,mid,end);
    }
    return count;
}
int reversePairs(vector<int> &arr, int n){
    // Write your code here.    
    return divide(arr,0,arr.size()-1);
}