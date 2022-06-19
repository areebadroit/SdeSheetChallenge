#include<bits/stdc++.h>
struct activity{
    int startTime;
    int endTime;
    int index;
};
static bool comparator(activity a, activity b){
    if(a.endTime<b.endTime)return true;
    else if(a.endTime==b.endTime){
        if(a.index<b.index) return true;
    }
    return false;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n = start.size();
    vector<activity> aL;
    for(int i=0;i<n;i++){
        struct activity act;
        act.startTime = start[i];
         act.endTime = finish[i];
         act.index = i+1;
        aL.push_back(act);
    }
    sort(aL.begin(),aL.end(),comparator);
    int count = 1;
    int lastActivityEndTime = aL[0].endTime;
    for(int i=1;i<n;i++){
        if(lastActivityEndTime<=aL[i].startTime){
            count++;
            lastActivityEndTime = aL[i].endTime;
        }
    }
    return count;
}