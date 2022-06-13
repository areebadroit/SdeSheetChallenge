//Day 4 Largest Subarray with 0 Sum

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code hxere
        unordered_map<int,int> hashMap;
        int maxCount = 0;
        int sum=0;//prefix Sum
        for(int i=0;i<n;i++){
            int count = 0;
            sum+=A[i];
            if(sum==0) {
                hashMap[sum]=i;
                count=i+1-0;
            }
            else if(hashMap.find(sum)==hashMap.end()){
                hashMap[sum]=i;
            }
            else{
                count = i-hashMap[sum];
            }
            maxCount = max(maxCount,count);
        }
        return maxCount;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends