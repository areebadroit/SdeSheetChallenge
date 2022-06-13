int Solution::solve(vector<int> &A, int B) {
    int xR = 0;
    int count = 0;
    unordered_map<int,int> mp;
    for(int i=0;i<A.size();i++){
        xR = xR^A[i];
        if(xR==B) count++;
        if(mp.find(xR^B)!=mp.end()){
            count+=mp[xR^B];
        }
        mp[xR]++;
    }
    return count;
}
