#include<bits/stdc++.h>
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
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n = start.size();
    vector<meeting> slots;
        for(int i=0;i<n;i++){
            struct meeting meet;
            meet.startTime = start[i];
            meet.endTime = end[i];
            meet.index = i+1;
            slots.push_back(meet);
        }
        sort(slots.begin(),slots.end(),comparator);
        vector<int> schedule;
    schedule.push_back(slots[0].index);
        int lastMeetEndTime = slots[0].endTime;
        for(int i=1;i<n;i++){
            if(lastMeetEndTime<slots[i].startTime){
                schedule.push_back(slots[i].index);
                lastMeetEndTime = slots[i].endTime;
            }
        }
        return schedule;
    
}