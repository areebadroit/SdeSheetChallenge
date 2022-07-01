bool isPossible(int presentNode, bool graph[101][101], int n,vector<int> &color, int selectedColor){
    //basically checking that the adjacent node of the presentNode is not colored with the same color
    for(int i=0;i<n;i++){
        if(i!=presentNode && graph[i][presentNode] == 1 && color[i] == selectedColor) return false;
    }
    return true;
}
bool graphColoring(int presentNode, bool graph[101][101],int m, int n,vector<int> &color){
    if(presentNode == n){
        return true;
    }
    for(int i = 1;i <= m;i++){
        if(isPossible(presentNode,graph,n,color,i)){
            color[presentNode]=i;
            if(graphColoring(presentNode+1, graph, m, n, color)) return true;
            color[presentNode]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    vector<int> color(n+1,0);//basically a kind of map to track which node is colored with which color
    if(graphColoring(0, graph, m, n, color)) return true;
    return false;
}