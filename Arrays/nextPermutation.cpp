#include<bits/stdc++.h>
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int breakPointIndex = permutation.size()-2;
    int index = permutation.size()-1;
    while(breakPointIndex>=0){
        if(permutation[breakPointIndex]<permutation[breakPointIndex+1])
            break;
        breakPointIndex--;
    }
    if(breakPointIndex<0){
        reverse(permutation.begin(),permutation.end());
    }else{
        while(index>breakPointIndex){
            if(permutation[index]>permutation[breakPointIndex]){
                break;
            }
            index--;
        }
        swap(permutation[index],permutation[breakPointIndex]);
        reverse(permutation.begin()+breakPointIndex+1,permutation.end());
    }
    return permutation;
}