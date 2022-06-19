class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int k = 0;
        int count = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]){
                
            }else{
                k+=1;
                nums[k]=nums[i];
                count++;
            }
        }
        return count;
    }
};