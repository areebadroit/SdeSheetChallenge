//Day 4 Longest Consecutive Sequence
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int> hashSet;
        int lcs = INT_MIN;
        for(int i=0;i<nums.size();i++){
            hashSet.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(hashSet.find(nums[i]-1)!=hashSet.end()){
                //do not do anything
            }else{
                //does not exist
                int el = nums[i];//we got the smallest element  for that sequence
                int count = 1;
                while(hashSet.find(el+1)!=hashSet.end()){
                    el++;
                    count++;
                }
                lcs = max(lcs,count);
            }
        }
        return lcs;
    }
};