//Day 3
class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int majorityElement = 0;
        int potentialMajorityELementCount = 0;
        for(int index=0;index<arr.size();index++){
            if(potentialMajorityELementCount == 0){
                majorityElement = arr[index];
            }
            if(arr[index]==majorityElement){
                potentialMajorityELementCount++;
            }else{
                potentialMajorityELementCount--;
            }
        }
        return majorityElement;
    }
};