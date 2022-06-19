// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comparator(Job a, Job b){
        if(a.profit>b.profit) return true;
        return false;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
        int maxProfit = 0;
        int jobCount = 0;
        int maxDeadLine = 0;
        for(int i=0;i<n;i++){
            maxDeadLine = max(maxDeadLine,arr[i].dead);
        }
        vector<int> slots(maxDeadLine+1,-1);
        sort(arr,arr+n,comparator);
        for(int i=0;i<n;i++){
            int it = arr[i].dead;
            while(it>0){
                if(slots[it] == -1){
                    slots[it] = arr[i].id;
                    maxProfit += arr[i].profit;
                    jobCount++;
                    break;
                }
                it--;
            }
        }
        return {jobCount,maxProfit};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends