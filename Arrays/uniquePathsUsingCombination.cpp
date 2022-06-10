class Solution {
public:
    int ncr_basic(int n, int r){
        int ans=1;
        for(size_t i = 1; i <= min(r,n-r);i++){
            ans = (ans*(n-i+1))/i;
        }
        return ans;
    }
    int uniquePaths(int m, int n) {
        return ncr_basic(n+m-2,m-1);
    }
};