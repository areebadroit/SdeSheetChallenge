class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = (low+high) >> 1;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[low]<=nums[mid]){//left half is sorted
                if(nums[low]<=target&&target<=nums[mid]){//assuming answer lies in left half
                    high = mid - 1;
                }else{//answer not found in left half
                    low = mid + 1;
                }
            }else{//right half is sorted
                if(target>=nums[mid]&&target<=nums[high]){//assuming answer lies in right half
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};