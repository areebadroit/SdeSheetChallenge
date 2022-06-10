//Day 3
#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
    // Write your code here.
    pair<int,int> majority;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        int item = arr[i];
        if(mp.find(item)!=mp.end()){
            mp[item]++;  
        }else{
            mp[item] = 1;
        }
        if(mp[item]>majority.second){
            majority.second = mp[item];
            majority.first = item;
        }
    }
    if(majority.second>floor(n/2)){
        return majority.first;
    }
    return -1;
}