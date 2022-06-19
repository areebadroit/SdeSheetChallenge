#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comparator(Item a, Item b){
        if((double)a.value/(double)a.weight>(double)b.value/(double)b.weight) return true;
        return false;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comparator);
        double knapsack = W;
        int i=0;
        double maxValue = 0.0;
        while(knapsack!=0&&i<n){
            if(arr[i].weight<=knapsack){
                knapsack-=arr[i].weight;
                maxValue+=arr[i].value;
            }else{//arr[i].weight>knapsack
                maxValue += (double)((double)arr[i].value/(double)arr[i].weight)*knapsack;
                knapsack = 0;
            }
            i++;
        }
        return maxValue;
        
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends