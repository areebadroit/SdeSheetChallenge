//Day 4 leetcode Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> hashMap;
        for(int index = 0;index<nums.size();index++){
            if(hashMap.find(target-nums[index])!=hashMap.end()){
                return {index,hashMap[target-nums[index]]};
            }else{
                hashMap[nums[index]] = index;
            }
        }
        
        return result;
    }
};