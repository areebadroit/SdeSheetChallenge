class Solution {
public:
    void combinationSumHelper(int index, vector<int> &ds, vector<vector<int>> &combination,vector<int>& candidates, int target){
        if(target == 0){
            combination.push_back(ds);
            return;
        }
        if(index==candidates.size()){
            return;
        }
        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            combinationSumHelper(index, ds, combination, candidates, target-candidates[index]);
            ds.pop_back();
        }
        combinationSumHelper(index+1, ds, combination, candidates, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combination;
        vector<int> ds;
        combinationSumHelper(0, ds, combination, candidates, target);
        return combination;
    }
};