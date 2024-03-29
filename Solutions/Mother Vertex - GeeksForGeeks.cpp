//https://practice.geeksforgeeks.org/problems/mother-vertex/1

/*This is a function problem.You only need to complete the function given below*/
/*
 * Function to find if there is a mother vertex in the given graph 
 * V: number of vertices in the graph
 * adj[]: graph representation
 */

void dfs(int u, vector<int> adj[], vector<bool> &vs){
    vs[u] = true;
    
    for (int i = 0; i < adj[u].size(); ++i){
        int v = adj[u][i];
        
        if (!vs[v]){
            dfs(v, adj, vs);
        }
    }
}
 
int findMother(int V, vector<int> adj[]) { 
    vector<bool> vs(V + 10, false);
    int moVer = 0;
    
    for (int i = 0; i < V; ++i){
        if (!vs[i]){
            dfs(i, adj, vs);
            moVer = i;
        }
    }
    
    fill(vs.begin(), vs.end(), false);
    dfs(moVer, adj, vs);
    
    for (int i = 0; i < V; ++i){
        if (!vs[i]){
            return -1;
        }
    }
    
    return moVer;
}