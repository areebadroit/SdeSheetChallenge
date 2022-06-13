//Day 4, Quadruplet which sums up to a target
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
        if(n==0) return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int left = j+1;
                int right = n-1;
                long long two_sum = nums[i]+nums[j];
                while(left<right){
                    if(two_sum+nums[left]+nums[right] == target){
                        vector<int> quadruplet(4,0);
                        quadruplet[0]=nums[i];
                        quadruplet[1]=nums[j];
                        quadruplet[2]=nums[left];
                        quadruplet[3]=nums[right];
                        result.push_back(quadruplet);
                        while(left<right && nums[left]==quadruplet[2]) ++left;
                        while(left<right && nums[right]==quadruplet[3]) --right;
                    }else if(two_sum+nums[left]+nums[right] <target){
                        left++;
                    }else{
                        right--;
                    }
                }
                
                while(j+1<n && nums[j]==nums[j+1]){++j;}
                    
            }
            
            while(i+1<n && nums[i]==nums[i+1]){++i;}
        }
        return result;
    }
};