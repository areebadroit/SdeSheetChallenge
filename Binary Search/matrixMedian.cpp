int countSmallerThanEqualToMid(vector<int> &row, int mid){
    int l = 0, h = row.size()-1;
    while(l<=h){
        int md = (l+h) >> 1;
        if(row[md] <= mid){
            l=md+1;
        }else{
            h=md-1; 
        }
    }
    return l;//since l is pointing to the upper-bound of mid, and we have 0 based indexing l will be actually the n of element <= mid
}
int Solution::findMedian(vector<vector<int> > &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int low = INT_MAX;
    int high = INT_MIN;
    for(int i=0;i<n;i++){
        low=min(low,matrix[i][0]);
    }
    for(int i=0;i<n;i++){
        high=max(high,matrix[i][m-1]);
    }
    //     int low = 1;
    // int high = 1e9;
    
    while(low<=high){
        int mid = (low+high) >> 1;
        int cnt = 0;
        for (int i=0;i<n;i++){
            cnt+=countSmallerThanEqualToMid(matrix[i],mid);
        }
        if(cnt<=(n*m)/2)
            low = mid+1;
        else
            high = mid-1;
    }
    return low;
}
