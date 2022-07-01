class Solution{
    public:
    void findPath(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &visited, vector<string> &ans, string s,int n){
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        //down
        if(i+1<n && !visited[i+1[j] && matrix[i+1][j]){
            visited[i][j] = 1;
            findPath(i+1, j, matrix, visited, ans, s+'D',n);
            visited[i][j] = 0;
        }
        //left
        if(j-1>=0 &&!visited[i][j-1] && matrix[i][j-1]){
            visited[i][j] = 1;
            findPath(i, j-1, matrix, visited, ans, s+'L',n);
            visited[i][j] = 0;
        }
        //right
         if(j+1<n &&!visited[i][j+1] && matrix[i][j+1]){
            visited[i][j] = 1;
            findPath(i, j+1, matrix, visited, ans, s+'R',n);
            visited[i][j] = 0;
        }
        //up
         if(i-1>=0 && !visited[i-1][j] && matrix[i-1][j]){
            visited[i][j] = 1;
            findPath(i-1, j, matrix, visited, ans, s+'U',n);
            visited[i][j] = 0;
        }
        
    }
    vector<string> findPath(vector<vector<int>> &matrix, int n) {
        // Your code goes here
        vector<vector<int>> visited(n,vector<int>(n,0));
        string s;
        vector<string> ans;
        if(matrix[0][0]==1 ){
            findPath(0, 0, matrix, visited, ans, s, n);
        }
        return ans;
    }
};`