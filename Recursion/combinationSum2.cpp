class Solution {
public:
    void combinationSum2(int index, vector<int> &ds, vector<vector<int>> &combination, vector<int>& candidates, int target){
        if(target == 0){
            combination.push_back(ds);
            return;
        }
        for(int i= index;i<candidates.size();i++){
            if(i>index&& candidates[i]==candidates[i-1]) continue;
            if(candidates[i]<=target){
                ds.push_back(candidates[i]);
                combinationSum2(i+1, ds, combination, candidates, target-candidates[i]);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> combination;
        vector<int> ds;
        combinationSum2(0, ds, combination, candidates, target);
        return combination;
    }
};