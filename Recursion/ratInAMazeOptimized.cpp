class Solution{

public:

    void findPath(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &visited, vector<string> &ans, string s,int n, int di[],int dj[]){
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        string dir = "DLRU";
        for(int ind=0;ind<4;ind++){
            int nexti = i+di[ind];
            int nextj = j+dj[ind];
            if(nexti>=0 && nexti<n && nextj>=0 && nextj<n && !visited[nexti][nextj] && maze[nexti][nextj]){
                visited[i][j] = 1;
                findPath(nexti, nextj, maze, visited, ans, s+dir[ind],n,di,dj);
                visited[i][j] = 0;
            }
        }
        
    }
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        // Your code goes here
        vector<vector<int>> visited(n,vector<int>(n,0));
        string s;
        vector<string> ans;
        int di[] = {1,0,0,-1};
        int dj[] = {0,-1,1,0};
        if(maze[0][0]==1 ){
            findPath(0, 0, maze, visited, ans, s, n,di,dj);
        }
        return ans;
    }
};
