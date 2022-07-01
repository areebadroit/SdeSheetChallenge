class Solution {
public:
    void permute(int index, vector<int>& ds, vector<vector<int>> & result, vector<int> &mapNums, vector<int>& nums){
        if(ds.size()==nums.size()){
            result.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!mapNums[i]){
                mapNums[i]=1;
                ds.push_back(nums[i]);
                permute(i+1,ds,result,mapNums,nums);
                mapNums[i]=0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ds;
        vector<int> mapNums(nums.size(),0);
        permute(0,ds,result,mapNums,nums);
        return result;
    }
};