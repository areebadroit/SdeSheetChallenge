#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
     int nums1 = -1;
    int nums2 = -1;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==nums1){
            cnt1++;
        }
        else if(arr[i]==nums2){
            cnt2++;
        }
        else if(cnt1 == 0){
            nums1=arr[i];
            cnt1++;
        }
        else if(cnt2 == 0){
            nums2 = arr[i];
            cnt2++;
        }else{
            cnt1--;
            cnt2--;
        }
    }
    int nums1Cnt = 0;
    int nums2Cnt = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==nums1) nums1Cnt++;
        if(arr[i]==nums2) nums2Cnt++;
    }
    vector<int> ans;
    if(nums1Cnt>floor(arr.size()/3)) ans.push_back(nums1);
    if(nums2Cnt>floor(arr.size()/3)) ans.push_back(nums2);
    return ans;
}