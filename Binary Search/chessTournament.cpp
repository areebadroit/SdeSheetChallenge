#include<bits/stdc++.h>
bool isPossible(vector<int> &positions, int mid, int c){
    int prevAllocationIndex = positions[0];
    int allocationCount = 1;
    for(int i=1;i<positions.size();i++){
        if(positions[i]-prevAllocationIndex>=mid){
            prevAllocationIndex = positions[i];
            allocationCount++;
        }
        if(allocationCount == c) return true;
    }
    return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
    sort(positions.begin(),positions.end());
    int low = 0;
    int high = positions[n-1]-low;
    int focusLevel = 0;
    while(low<=high){
        int mid = (low+high)>>1;
        if(isPossible(positions,mid,c)){
            focusLevel = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return focusLevel;
}