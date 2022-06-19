#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    struct meeting{
        int startTime;
        int endTime;
        int index;
    };
    static bool comparator(meeting m1, meeting m2){
        if(m1.endTime<m2.endTime){
            return true;
        }
        else if(m1.endTime==m2.endTime){
            if(m1.index<m2.index){
                return true;
            }
        }
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<meeting> slots;
        for(int i=0;i<n;i++){
            struct meeting meet;
            meet.startTime = start[i];
            meet.endTime = end[i];
            meet.index = i+1;
            slots.push_back(meet);
        }
        sort(slots.begin(),slots.end(),comparator);
        int count = 1;
        int lastMeetEndTime = slots[0].endTime;
        for(int i=1;i<n;i++){
            if(lastMeetEndTime<slots[i].startTime){
                count++;
                lastMeetEndTime = slots[i].endTime;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends