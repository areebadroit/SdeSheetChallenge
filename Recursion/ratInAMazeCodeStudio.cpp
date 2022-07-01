void findPath(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &visited, vector<vector<int>> &ans, string s,int n, int di[],int dj[]){
        if(i==n-1 && j==n-1){
            vector<int> temp;
            for(int p=0;p<n;p++){
                for(int q=0;q<n;q++){
                    temp.push_back(visited[p][q]);
                }
            }
            temp[n*n-1]=1;
            ans.push_back(temp);
            temp[n*n-1]=0;
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
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
     vector<vector<int>> visited(n,vector<int>(n,0));
        string s;
        vector<vector<int>> ans;
        int di[] = {1,0,0,-1};
        int dj[] = {0,-1,1,0};
        if(maze[0][0]==1 ){
            findPath(0, 0, maze, visited, ans, s, n,di,dj);
        }
        return ans;
}