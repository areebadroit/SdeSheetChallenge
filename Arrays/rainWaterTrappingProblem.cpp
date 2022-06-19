//Trapping Rain Water Problem
//Better Approach using prefix and suffix sum
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefixMax(n,0);
        for(int i=0;i<n;i++){
            if(i==0){
                prefixMax[i]=height[i];
            }else{
                prefixMax[i]=max(prefixMax[i-1],height[i]);
            }
            
        }
        vector<int> suffixMax(n,0);
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                suffixMax[i]=height[i];
            }else{
            suffixMax[i] = max(suffixMax[i+1],height[i]);
            }
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            int temp = 0;
            
            temp=min(prefixMax[i],suffixMax[i])-height[i];
            if(temp>0) sum+=temp;
        }
        return sum;
    }
};
//Optimal Approach
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int leftMax = INT_MIN;
        int rightMax = INT_MIN;
        int sum = 0;
        while(left<right){
            if(height[left]<height[right]){
                if(leftMax<height[left]){
                    leftMax = height[left];
                }else{
                    sum+=(leftMax-height[left]);
                }
                left++;
            }else{
                if(rightMax<height[right]){
                    rightMax = height[right];
                }else{
                    sum+=(rightMax-height[right]);
                }
                right--;
            }
        }
        return sum;
    }
};