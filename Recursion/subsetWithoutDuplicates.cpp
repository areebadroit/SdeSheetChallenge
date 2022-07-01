class Solution {
public:
    void subsetsWithDup(int index, vector<int> &ds,vector<vector<int>> &result, vector<int> &nums){
        result.push_back(ds);
        for(int i=index;i<nums.size();i++){
            if(i>index&&nums[i]==nums[i-1])continue;
                ds.push_back(nums[i]);
                subsetsWithDup(i+1, ds, result, nums);
                ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        subsetsWithDup(0, ds, result, nums);
        return result;
    }
};